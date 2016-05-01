##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 3 of the License, or
## any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License along
## with this program; If not, see <http://www.gnu.org/licenses/>.
##
## Copyright (C) 2016 Martin-Pierrat Louis (louismartinpierrat@gmail.com)
##



## CMAKE INITIALISATION

PROJECT(Engine)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake/)

## END CMAKE INITIALISATION



## PROJECT VERSION

SET(PROJECT_VERSION_MAJOR 2)
SET(PROJECT_VERSION_MINOR 2)
SET(PROJECT_VERSION_PATCH 1)
SET(PROJECT_VERSION_EXTRA 0)

SET(PROJECT_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})
SET(PROJECT_VERSION_FULL ${PROJECT_VERSION}.${PROJECT_VERSION_EXTRA})

## END PROJECT VERSION

## PROJECT CONFIGURATION

SET(PROJECT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/)
SET(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/source/)

SET(RESOURCES_PATH ${CMAKE_SOURCE_DIR}/resources)

CONFIGURE_FILE(
    ${PROJECT_INCLUDE_DIR}/Engine/Version.hpp.in
    ${PROJECT_INCLUDE_DIR}/Engine/Version.hpp
    )

CONFIGURE_FILE(
    ${PROJECT_INCLUDE_DIR}/Engine/Configuration.hpp.in
    ${PROJECT_INCLUDE_DIR}/Engine/Configuration.hpp
    )

## END PROJECT CONFIGURATION

## IDE CONFIGURATION

FILE(GLOB_RECURSE LibFiles "${CMAKE_SOURCE_DIR}/include/*.hpp")
add_custom_target(headers SOURCES ${LibFiles})

## END IDE CONFIGURATION

## TEST CONFIGURATION

INCLUDE(ExternalProject)

IF ( MSVC )

    SET(EXTERNAL_PROJECT_CMAKE_ARGS
        -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG:PATH=.
        -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE:PATH=.
        -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY=PATH.
        -DBUILD_GTEST=ON
    )

ELSE ()

    SET(EXTERNAL_PROJECT_CMAKE_ARGS
        -DBUILD_GTEST=ON
    )

ENDIF()

EXTERNALPROJECT_ADD(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    CMAKE_ARGS ${EXTERNAL_PROJECT_CMAKE_ARGS}
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}
    INSTALL_COMMAND ""
    )

EXTERNALPROJECT_GET_PROPERTY(googletest source_dir)
SET(GTEST_INCLUDE_DIRS ${source_dir}/googletest/include)

EXTERNALPROJECT_GET_PROPERTY(googletest BINARY_DIR)
SET(GTEST_LIBS_DIR ${BINARY_DIR}/googlemock/gtest/)

FUNCTION(CXX_TEST name sources)

    ADD_EXECUTABLE(${name} ${sources})
    ADD_DEPENDENCIES(${name} googletest)
    TARGET_LINK_LIBRARIES(${name}
        ${GTEST_LIBS_DIR}/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_STATIC_LIBRARY_SUFFIX}
        ${GTEST_LIBS_DIR}/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${CMAKE_STATIC_LIBRARY_SUFFIX}
        ${CMAKE_PROJECT_NAME}
    )
    TARGET_LINK_LIBRARIES(${name} ${CMAKE_THREAD_LIBS_INIT})

    IF (CMAKE_COMPILER_IS_GNUCXX)
        TARGET_COMPILE_OPTIONS(${name} PRIVATE -std=c++14)
    ENDIF()

    TARGET_INCLUDE_DIRECTORIES(${name} PRIVATE ${GTEST_INCLUDE_DIRS})
    ADD_TEST(${name} ${name})

ENDFUNCTION()

## END TEST CONFIGURATION



## PROJECT LANGUAGE

ENABLE_LANGUAGE(CXX)

## END PROJECT LANGUAGE



## FIND LIBRARY DEPENDENCY

FIND_PACKAGE(OpenGL REQUIRED)
FIND_PACKAGE(GLEW REQUIRED)
FIND_PACKAGE(Devil REQUIRED)
FIND_PACKAGE(Assimp REQUIRED)
FIND_PACKAGE(Log4cpp REQUIRED)
#FIND_PACKAGE(RapidXml REQUIRED)
FIND_PACKAGE(Threads REQUIRED)
FIND_PACKAGE(glm REQUIRED)
FIND_PACKAGE(OpenAL REQUIRED)
FIND_PACKAGE(Alut REQUIRED)

## END FIND LIBRARY DEPENDENCY


## PROJECT SOURCES FILES

FILE(GLOB_RECURSE PROJECT_SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/*.cpp
    )

## END PROJECT SOURCES FILES



## PROJECT HEADERS FILES

SET(GLOB_RECURSE PROJECT_INCLUDE_FILES
    ${PROJECT_INCLUDE_DIR}/*.hpp
    )

## END PROJECT HEADERS FILES



## PROJECT INCLUDES DIRECTORIES

INCLUDE_DIRECTORIES(
    ${PROJECT_INCLUDE_DIR}
    ${OPENGL_INCLUDE_DIR}
    ${GLEW_INCLUDE_DIRS}
    ${ASSIMP_INCLUDE_DIR}
    ${DevIL_INCLUDE_DIR}
    ${LOG4CPP_INCLUDE_DIR}
    ${GLM_INCLUDE_DIRS}
    ${OPENAL_INCLUDE_DIR}
    ${ALUT_INCLUDE_DIR}
    )

## END PROJECT INCLUDES DIRECTORIES



## PROJECT SETTINGS

## END PROJECT SETTINGS



## BINARY SETTINGS

ADD_LIBRARY(${CMAKE_PROJECT_NAME} SHARED ${PROJECT_SOURCE_FILES})

## END BINARY SETTINGS



## COMPILATION SETTINGS

TARGET_COMPILE_DEFINITIONS(${CMAKE_PROJECT_NAME} PRIVATE BUILD_SHARED_LIBRARIES)

IF (CMAKE_COMPILER_IS_GNUCXX)

    # Warn when a class seems unusable because all the constructors or
    # destructors in that class are private, and it has neither friends nor
    # public static member functions. Also warn if there are no non-private
    # methods, and there's at least one private member function that isn't a
    # constructor or destructor.
    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wctor-dtor-privacy)

    # Warn when a noexcept-expression evaluates to false because of a call to a
    # function that does not have a non-throwing exception specification
    # (i.e. throw() or noexcept) but is known by the compiler to never throw
    # an exception.
    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wnoexcept)

    # Warn when a class has virtual functions and an accessible non-virtual
    # destructor itself or in an accessible polymorphic base class, in which
    # case it is possible but unsafe to delete an instance of a derived class
    # through a pointer to the class itself or base class. This warning is
    # automatically enabled if -Weffc++ is specified.
    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wnon-virtual-dtor)

    # Warn about violations of the following style guidelines from Scott Meyers' Effective C++ series of books:
    #
    #   - Define a copy constructor and an assignment operator for classes with
    # dynamically-allocated memory.
    #   - Prefer initialization to assignment in constructors.
    #   - Have operator= return a reference to *this.
    #   - Don't try to return a reference when you must return an object.
    #   - Distinguish between prefix and postfix forms of increment and decrement operators.
    #   - Never overload &&, ||, or ,.
    #
    # This option also enables -Wnon-virtual-dtor, which is also one of the
    # effective C++ recommendations. However, the check is extended to warn
    # about the lack of virtual destructor in accessible non-polymorphic bases
    # classes too.
    #
    # When selecting this option, be aware that the standard library headers do
    # not obey all of these guidelines; use ‘grep -v’ to filter out those
    # warnings.
    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Weffc++)

    # Warn about the use of an uncasted NULL as sentinel. When compiling only
    # with GCC this is a valid sentinel, as NULL is defined to __null. Although
    # it is a null pointer constant rather than a null pointer, it is guaranteed
    # to be of the same size as a pointer. But this use is not portable across
    # different compilers.
    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wstrict-null-sentinel)

    # Warn if an old-style (C-style) cast to a non-void type is used within a
    # C++ program. The new-style casts (dynamic_cast, static_cast,
    # reinterpret_cast, and const_cast) are less vulnerable to unintended
    # effects and much easier to search for.
    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wold-style-cast)

    # Warn when a function declaration hides virtual functions from a base
    # class. For example, in:
    #
    # struct A {
    #       virtual void f();
    # };
    #
    # struct B: public A {
    #       void f(int);
    # };
    #
    # the A class version of f is hidden in B, and code like:
    #
    #   B* b;
    #   b->f();
    #
    # fails to compile.
    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Woverloaded-virtual)

    # Disable the diagnostic for converting a bound pointer to member function
    # to a plain pointer.
    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wno-pmf-conversions)

    # Warn when overload resolution chooses a promotion from unsigned or
    # enumerated type to a signed type, over a conversion to an unsigned type
    # of the same size.
    #
    # Previous versions of G++ tried to preserve unsignedness, but the standard
    # mandates the current behavior.
    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wsign-promo)

    # Warn when a class is defined with multiple direct base classes.
    # Some coding rules disallow multiple inheritance, and this may be used to
    # enforce that rule.
    # The warning is inactive inside a system header file, such as the STL, so
    # one can still use the STL.
    # One may also define classes that indirectly use multiple inheritance.
    #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wmultiple-inheritance)

    # Warn when a class is defined with a virtual direct base classe.
    # Some coding rules disallow multiple inheritance, and this may be used to
    # enforce that rule. The warning is inactive inside a system header file,
    # such as the STL, so one can still use the STL.
    # One may also define classes that indirectly use virtual inheritance.
    #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wvirtual-inheritance)


    # Give a warning when a value of type float is implicitly promoted to
    # double. CPUs with a 32-bit “single-precision” floating-point unit
    # implement float in hardware, but emulate double in software.
    #
    # On such a machine, doing computations using double values is much more
    # expensive because of the overhead required for software emulation.
    #
    # It is easy to accidentally do computations with double because
    # floating-point literals are implicitly of type double. For example, in:
    #
    #       float area(float radius)
    #       {
    #           return 3.14159 * radius * radius;
    #       }
    #
    # the compiler performs the entire computation with double because the
    # floating-point literal is a double.
    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wdouble-promotion)

    # Warn if a user-supplied include directory does not exist.
    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wmissing-include-dirs)

    # Warn whenever a switch statement does not have a default case.
    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wswitch-default)

    # Warn whenever a switch statement has an index of enumerated type and lacks
    # a case for one or more of the named codes of that enumeration.
    # case labels outside the enumeration range also provoke warnings when this
    # option is used.
    #
    # The only difference between -Wswitch and this option is that this option
    # gives a warning about an omitted enumeration code even if there is a
    # default label.
    #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wswitch-enum)

    # Warn about functions that might be candidates for attributes pure, const
    # or noreturn.
    #
    # The compiler only warns for functions visible in other compilation units
    # or (in the case of pure and const) if it cannot prove that the function
    # returns normally. A function returns normally if it doesn't contain an
    # infinite loop or return abnormally by throwing, calling abort or trapping.
    #
    # This analysis requires option -fipa-pure-const, which is enabled by
    # default at -O and higher.
    #
    # Higher optimization levels improve the accuracy of the analysis.
    #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wsuggest-attribute=pure)
    #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wsuggest-attribute=const)
    #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wsuggest-attribute=noreturn)

    # Warn about types with virtual methods where code quality would be improved
    # if the type were declared with the C++11 final specifier, or, if possible,
    # declared in an anonymous namespace.
    #
    # This allows GCC to more aggressively devirtualize the polymorphic calls.
    #
    # This warning is more effective with link time optimization, where the
    # information about the class hierarchy graph is more complete.
    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wsuggest-final-types)

    # Warn about virtual methods where code quality would be improved if the
    # method were declared with the C++11 final specifier, or, if possible, its
    # type were declared in an anonymous namespace or with the final specifier.
    #
    # This warning is more effective with link time optimization, where the
    # information about the class hierarchy graph is more complete. It is
    # recommended to first consider suggestions of -Wsuggest-final-types and
    # then rebuild with new annotations.
    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wsuggest-final-methods)

    # Warn about overriding virtual functions that are not marked with the
    # override keyword.
    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wsuggest-override)

    # Warn about duplicated conditions in an if-else-if chain. For instance,
    # warn for the following code:
    #
    #   if (p->q != NULL) { ...  }
    #   else if (p->q != NULL) { ...  }
    #
    #TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wduplicated-cond)

    # Warn if floating-point values are used in equality comparisons.
    #
    # The idea behind this is that sometimes it is convenient (for the
    # programmer) to consider floating-point values as approximations to
    # infinitely precise real numbers.
    #
    # If you are doing this, then you need to compute (by analyzing the code,
    # or in some other way) the maximum or likely maximum error that the
    # computation introduces, and allow for it when performing comparisons
    # (and when producing output, but that's a different problem).
    #
    # In particular, instead of testing for equality, you should check to see
    # whether the two values have ranges that overlap; and this is done with
    # the relational operators, so equality comparisons are probably mistaken.
    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wfloat-equal)

    # Warn when a literal ‘0’ is used as null pointer constant. This can be
    # useful to facilitate the conversion to nullptr in C++11.
    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wzero-as-null-pointer-constant)

    # Warn when an expression is casted to its own type.
    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wuseless-cast)

    # Warn for implicit conversions that may alter a value.
    #
    # This includes conversions between real and integer, like abs (x) when x is
    # double; conversions between signed and unsigned, like unsigned ui = -1;
    # and conversions to smaller types, like sqrtf (M_PI).
    #
    # Do not warn for explicit casts like abs ((int) x) and ui = (unsigned) -1,
    # or if the value is not changed by the conversion like in abs (2.0).
    #
    # Warnings about conversions between signed and unsigned integers can be
    # disabled by using -Wno-sign-conversion.
    #
    # For C++, also warn for confusing overload resolution for user-defined
    # conversions; and conversions that never use a type conversion operator:
    # conversions to void, the same type, a base class or a reference to them.
    # Warnings about conversions between signed and unsigned integers are
    # disabled by default in C++ unless -Wsign-conversion is explicitly enabled.
    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wconversion)

    # Warn about suspicious uses of logical operators in expressions.
    #
    # This includes using logical operators in contexts where a bit-wise
    # operator is likely to be expected.
    # Also warns when the operands of a logical operator are the same:
    #
    #   extern int a;
    #   if (a < 0 && a < 0) { ...  }
    #
    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wlogical-op)

    # Warn if a global function is defined without a previous declaration. Do so
    # even if the definition itself provides a prototype. Use this option to
    # detect global functions that are not declared in header files.
    #
    # In C, no warnings are issued for functions with previous non-prototype
    # declarations; use -Wmissing-prototypes to detect missing prototypes.
    #
    # In C++, no warnings are issued for function templates, or for inline
    # functions, or for functions in anonymous namespaces.
    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wmissing-declarations)

    # Warn if a function that is declared as inline cannot be inlined.
    #
    # Even with this option, the compiler does not warn about failures to inline
    # functions declared in system headers.
    #
    # The compiler uses a variety of heuristics to determine whether or not to
    # inline a function. For example, the compiler takes into account the size
    # of the function being inlined and the amount of inlining that has already
    # been done in the current function.
    #
    # Therefore, seemingly insignificant changes in the source program can cause
    # the warnings produced by -Winline to appear or disappear.
    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Winline)

    # Warn whenever a local variable or type declaration shadows another
    # variable, parameter, type, class member (in C++), or instance variable
    # (in Objective-C) or whenever a built-in function is shadowed. Note that in
    # C++, the compiler warns if a local variable shadows an explicit typedef,
    # but not if it shadows a struct/class/enum.
    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wshadow)

    # This enables all the warnings about constructions that some users consider
    # questionable, and that are easy to avoid (or modify to prevent the
    # warning), even in conjunction with macros.
    #
    # This also enables some language-specific warnings described in C++ Dialect
    # Options and Objective-C and Objective-C++ Dialect Options.
    #
    # -Wall turns on the following warning flags:
    #
    #       -Waddress
    #       -Warray-bounds=1 (only with -O2)
    #       -Wbool-compare
    #       -Wc++11-compat  -Wc++14-compat
    #       -Wchar-subscripts
    #       -Wcomment
    #       -Wenum-compare (in C/ObjC; this is on by default in C++)
    #       -Wformat
    #       -Wimplicit (C and Objective-C only)
    #       -Wimplicit-int (C and Objective-C only)
    #       -Wimplicit-function-declaration (C and Objective-C only)
    #       -Winit-self (only for C++)
    #       -Wlogical-not-parentheses
    #       -Wmain (only for C/ObjC and unless -ffreestanding)
    #       -Wmaybe-uninitialized
    #       -Wmemset-transposed-args
    #       -Wmisleading-indentation (only for C/C++)
    #       -Wmissing-braces (only for C/ObjC)
    #       -Wnarrowing (only for C++)
    #       -Wnonnull
    #       -Wopenmp-simd
    #       -Wparentheses
    #       -Wpointer-sign
    #       -Wreorder
    #       -Wreturn-type
    #       -Wsequence-point
    #       -Wsign-compare (only in C++)
    #       -Wsizeof-pointer-memaccess
    #       -Wstrict-aliasing
    #       -Wstrict-overflow=1
    #       -Wswitch
    #       -Wtautological-compare
    #       -Wtrigraphs
    #       -Wuninitialized
    #       -Wunknown-pragmas
    #       -Wunused-function
    #       -Wunused-label
    #       -Wunused-value
    #       -Wunused-variable
    #       -Wvolatile-register-var
    #
    # Note that some warning flags are not implied by -Wall. Some of them warn
    # about constructions that users generally do not consider questionable,
    # but which occasionally you might wish to check for; others warn about
    # constructions that are necessary or hard to avoid in some cases, and there
    # is no simple way to modify the code to suppress the warning.
    # Some of them are enabled by -Wextra but many of them must be enabled
    # individually.
    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wall)

    # This enables some extra warning flags that are not enabled by -Wall.
    # (This option used to be called -W. The older name is still supported,
    # but the newer name is more descriptive.)
    #
    #   -Wclobbered
    #   -Wempty-body
    #   -Wignored-qualifiers
    #   -Wmissing-field-initializers
    #   -Wmissing-parameter-type (C only)
    #   -Wold-style-declaration (C only)
    #   -Woverride-init
    #   -Wsign-compare (C only)
    #   -Wtype-limits
    #   -Wuninitialized
    #   -Wshift-negative-value (in C++03 and in C99 and newer)
    #   -Wunused-parameter (only with -Wunused or -Wall)
    #   -Wunused-but-set-parameter (only with -Wunused or -Wall)
    #
    # The option -Wextra also prints warning messages for the following cases:
    #
    # A pointer is compared against integer zero with <, <=, >, or >=.
    # (C++ only) An enumerator and a non-enumerator both appear in a conditional
    # expression.
    # (C++ only) Ambiguous virtual bases.
    # (C++ only) Subscripting an array that has been declared register.
    # (C++ only) Taking the address of a variable that has been declared
    # register.
    # (C++ only) A base class is not initialized in a derived class's copy
    # constructor.
    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wextra)

    # The 2014 ISO C++ standard plus amendments.
    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -std=c++14)

    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE
        $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:-g3>
        )

ENDIF()

## END COMPILATION SETTINGS



## LIBRARY SETTINGS

TARGET_LINK_LIBRARIES(${CMAKE_PROJECT_NAME}
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${ASSIMP_LIBRARY}
    ${LOG4CPP_LIBRARY}
    ${DevIL_LIBRARY_ILUT}
    ${DevIL_LIBRARY_ILU}
    ${DevIL_LIBRARY_IL}
    ${OPENAL_LIBRARY}
    ${ALUT_LIBRARY}
    )

IF (WIN32)
    TARGET_LINK_LIBRARIES(${CMAKE_PROJECT_NAME} wsock32 ws2_32)
ENDIF()

## END LIBRARY SETTINGS



## INSTALLATION SETTINGS

INSTALL(TARGETS ${CMAKE_PROJECT_NAME}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)

INSTALL(DIRECTORY ${PROJECT_INCLUDE_DIR}
    DESTINATION include
    FILES_MATCHING PATTERN "*.hpp"
    )

## END INSTALLATION SETTINGS



## TESTS

ENABLE_TESTING()

CXX_TEST(test1 test/test1.cpp)
CXX_TEST(test_core test/test_core.cpp)

## END TESTS



## DOXYGEN CONFIGURATION

FIND_PACKAGE(Doxygen QUIET)

IF (DOXYGEN_FOUND)

    CONFIGURE_FILE(
        ${CMAKE_SOURCE_DIR}/Doxyfile.in
        ${CMAKE_BINARY_DIR}/Doxyfile
        @ONLY)

    ADD_CUSTOM_TARGET(doc
        ${DOXYGEN_EXECUTABLE} ${CMAKE_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/source
        COMMENT "Generating API documentation with Doxygen" VERBATIM
        )

ENDIF (DOXYGEN_FOUND)

## END DOXYGEN CONFIGURATION

