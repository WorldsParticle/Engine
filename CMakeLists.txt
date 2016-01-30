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



## PROJECT LANGUAGE

ENABLE_LANGUAGE(CXX)

## END PROJECT LANGUAGE



## FIND LIBRARY DEPENDENCY

FIND_PACKAGE(OpenGL REQUIRED)
FIND_PACKAGE(GLEW REQUIRED)
#FIND_PACKAGE(Devil REQUIRED)
FIND_PACKAGE(Assimp REQUIRED)
FIND_PACKAGE(Log4cpp REQUIRED)
#FIND_PACKAGE(RapidXml REQUIRED)
FIND_PACKAGE(Threads REQUIRED)
FIND_PACKAGE(glm REQUIRED)

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
    #${DevIL_INCLUDE_DIR}
    ${LOG4CPP_INCLUDE_DIR}
    ${GLM_INCLUDE_DIRS}
    )

## END PROJECT INCLUDES DIRECTORIES



## PROJECT SETTINGS

IF (CMAKE_BUILD_TYPE MATCHES "debug")

    ADD_DEFINITIONS(-D__DEBUG__)

ELSE ()

    ADD_DEFINITIONS(-D__RELEASE__)

ENDIF ()

## END PROJECT SETTINGS



## BINARY SETTINGS

ADD_LIBRARY(${CMAKE_PROJECT_NAME} SHARED ${PROJECT_SOURCE_FILES})

## END BINARY SETTINGS



## COMPILATION SETTINGS

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

    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wall)
    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -Wextra)
    TARGET_COMPILE_OPTIONS(${CMAKE_PROJECT_NAME} PRIVATE -std=c++14)

ENDIF()

## END COMPILATION SETTINGS



## LIBRARY SETTINGS

TARGET_LINK_LIBRARIES(${CMAKE_PROJECT_NAME}
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${ASSIMP_LIBRARY}
    ${LOG4CPP_LIBRARY}
#    ${DevIL_LIBRARY_ILUT}
    #${DevIL_LIBRARY_ILU}
    #${DevIL_LIBRARY_IL}
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

INCLUDE_DIRECTORIES(${GTEST_INCLUDE_DIRS})

FUNCTION(CXX_TEST name sources)

    ADD_EXECUTABLE(${name} ${sources})
    ADD_DEPENDENCIES(${name} googletest)
    TARGET_LINK_LIBRARIES(${name}
        ${GTEST_LIBS_DIR}/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_STATIC_LIBRARY_SUFFIX}
        ${GTEST_LIBS_DIR}/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${CMAKE_STATIC_LIBRARY_SUFFIX}
        ${CMAKE_PROJECT_NAME}
    )
    TARGET_LINK_LIBRARIES(${name} ${CMAKE_THREAD_LIBS_INIT})
    TARGET_COMPILE_OPTIONS(${name} PRIVATE -std=c++14)
    ADD_TEST(${name} ${name})

ENDFUNCTION()

## END TEST CONFIGURATION



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
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/sources
        COMMENT "Generating API documentation with Doxygen" VERBATIM
        )

ENDIF (DOXYGEN_FOUND)

## END DOXYGEN CONFIGURATION

