# -Try to find DevIL (developer image) library
# formerly known as OpenIL, see
# http://openil.sourceforge.net
#
# Once run this will define: 
# 
# DevIL_FOUND
# DevIL_INCLUDE_DIR
# DevIL_LIBRARIES
#
# Jan Woetzel 12/2005. 
# 
# www.mip.informatik.uni-kiel.de/~jw
# --------------------------------

# base dirs:
SET(DevIL_POSSIBLE_ROOT_PATHS
    ${DevIL_ROOT_DIR} $ENV{DevIL_ROOT_DIR}
    ${DevIL_DIR} $ENV{DevIL_DIR}
    ${DEVIL_DIR} $ENV{DEVIL_DIR}
    ${DEVIL_HOME} $ENV{DEVIL_HOME}
    "$ENV{EXTERN_LIBS_DIR}/DevIL"
    $ENV{EXTRA_DIR} $ENV{EXTRA}
    $ENV{ProgramFiles}/DevIL
    /usr/local/ /usr/ /usr/lib/
    /opt/net/gcc41/DevIL
    /opt/net/gcc33/DevIL
    C:/library/DevIL
    "C:/Program Files/DevIL"
    C:/DevIL)

# appended
SET(DevIL_POSSIBLE_INCDIR_SUFFIXES include DevIL/include )
SET(DevIL_POSSIBLE_LIBDIR_SUFFIXES lib lib64)

FIND_PATH(DevIL_INCLUDE_DIR NAMES IL/il.h
    PATHS ${DevIL_POSSIBLE_ROOT_PATHS} PATH_SUFFIXES ${DevIL_POSSIBLE_INCDIR_SUFFIXES})
#MESSAGE("DBG DevIL_INCLUDE_DIR=${DevIL_INCLUDE_DIR}")

FIND_LIBRARY(DevIL_LIBRARY_IL
    NAMES DevIL devil DevIL IL
    PATHS ${DevIL_POSSIBLE_ROOT_PATHS} PATH_SUFFIXES ${DevIL_POSSIBLE_LIBDIR_SUFFIXES})
#MESSAGE("DBG DevIL_LIBRARY_IL=${DevIL_LIBRARY_IL}")

FIND_LIBRARY(DevIL_LIBRARY_ILU
    NAMES ILU ilu Ilu 
    PATHS ${DevIL_POSSIBLE_ROOT_PATHS} PATH_SUFFIXES ${DevIL_POSSIBLE_LIBDIR_SUFFIXES})
#MESSAGE("DBG DevIL_LIBRARY_ILU=${DevIL_LIBRARY_ILU}")

FIND_LIBRARY(DevIL_LIBRARY_ILUT
    NAMES ILUT ilu Ilut
    PATHS ${DevIL_POSSIBLE_ROOT_PATHS} PATH_SUFFIXES ${DevIL_POSSIBLE_LIBDIR_SUFFIXES})
#MESSAGE("DBG DevIL_LIBRARY_ILUT=${DevIL_LIBRARY_ILUT}")



# --------------------------------

IF (DevIL_INCLUDE_DIR)
    IF (DevIL_LIBRARY_IL)
	IF (DevIL_LIBRARY_ILU) #AND DevIL_LIBRARY_ILUT)
	    SET(DevIL_FOUND TRUE)
	    SET(DevIL_LIBRARIES 
		${DevIL_LIBRARY_IL}
		${DevIL_LIBRARY_ILU})
	    IF (DevIL_LIBRARY_ILUT)
		SET(DevIL_LIBRARIES ${DevIL_LIBRARIES} ${DevIL_LIBRARY_ILUT})
	    ENDIF (DevIL_LIBRARY_ILUT)

	    # get the link directory for rpath to be used with LINK_DIRECTORIES:	 
	    GET_FILENAME_COMPONENT(DevIL_LINK_DIRECTORIES ${DevIL_LIBRARY_IL} PATH)  
	ENDIF(DevIL_LIBRARY_ILU)# AND DevIL_LIBRARY_ILUT)
    ENDIF(DevIL_LIBRARY_IL)
ENDIF (DevIL_INCLUDE_DIR)


MARK_AS_ADVANCED( DevIL_INCLUDE_DIR DevIL_LIBRARY_IL DevIL_LIBRARY_ILU
    DevIL_LIBRARY_ILUT DevIL_LIBRARIES)

# ==========================================
IF(NOT DevIL_FOUND)
    # make FIND_PACKAGE friendly
    IF(NOT DevIL_FIND_QUIETLY)
	IF(DevIL_FIND_REQUIRED)
	    MESSAGE(FATAL_ERROR "DevIL required, please specify it's location.")
	ELSE(DevIL_FIND_REQUIRED)
	    MESSAGE(STATUS "ERROR: DevIL was not found.")
	ENDIF(DevIL_FIND_REQUIRED)
    ENDIF(NOT DevIL_FIND_QUIETLY)
ENDIF(NOT DevIL_FOUND)

# backward compatibility
SET(DEVIL_FOUND ${DevIL_FOUND})
SET(DEVIL_LIBRARIES ${DevIL_LIBRARIES})
SET(DEVIL_INCLUDE_DIR ${DevIL_INCLUDE_DIR})

if (WIN32) # Check if we are on Windows
    if (MSVC) # Check if we are using the Visual Studio compiler
	set_target_properties(FileMenu PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")
    elseif(CMAKE_COMPILER_IS_GNUCXX)
	# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows")
	# # Not tested
    else()
	message(SEND_ERROR "You are using an
	unsupported Windows compiler! (Not MSVC or GCC)")
    endif()
elseif (UNIX)
    set(CMAKE_PREFIX_PATH "/usr/lib64/qt5")
    SET(CMAKE_CXX_FLAGS "-std=c++0x")
    # Nothing special required
else ()
    message(SEND_ERROR "You are on an unsupported platform! (Not Win32 or Unix)")
ENDIF ()

cmake_minimum_required( VERSION 2.8.11 )
set (QT_USE_QTOPENGL TRUE)
find_package (Qt5Core REQUIRED QtWindow)
find_package (Qt5Widgets REQUIRED)
find_package (Qt5OpenGL REQUIRED)
find_package (OpenGL REQUIRED)
find_package (Assimp REQUIRED)
find_package (GLEW REQUIRED)
#INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})
qt5_wrap_ui(uifiles window/mainwindow.ui window/toolwidget.ui)
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/graphic ${CMAKE_CURRENT_SOURCE_DIR}/model
    ${CMAKE_CURRENT_SOURCE_DIR}/window ${CMAKE_CURRENT_SOURCE_DIR}/engine
    ${QT_QTOPENGL_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${ASSIMP_INCLUDE_DIR}
    ${DevIL_INCLUDE_DIR} ${GLEW_INCLUDE_PATH})
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#find_package(SFML REQUIRED system window graphics network audio)
# The QUIET option disables messages if the package cannot be found. 
FIND_PACKAGE(Qt5Widgets) 
SET(SOURCES main.cpp engine/gameclock.cpp engine/gameengine.cpp
    graphic/fire.cpp graphic/myglpainter.cpp
    model/model.cpp model/tools.cpp window/glwidget.cpp window/glwindow.cpp
    window/irrlichtwidget.cpp
    window/mainwindow.cpp window/toolwidget.cpp
    graphic/AssimpProgressHandlerOverload.cpp  graphic/GPUBuffer.cpp graphic/material.cpp
    graphic/mesh.cpp graphic/shader.cpp graphic/texture.cpp graphic/uniform.cpp)
SET(HEADERS main.h engine/gameclock.h engine/gameengine.h
    graphic/fire.h graphic/myglpainter.h
    model/model.h model/tools.h window/glwidget.h window/glwindow.h
    window/irrlichtwidget.h
    window/mainwindow.h window/toolwidget.h
    graphic/AssimpProgressHandlerOverload.h  graphic/GPUBuffer.h graphic/material.h
    graphic/mesh.h graphic/shader.h graphic/texture.h graphic/uniform.h)
add_executable(WorldsParticle ${SOURCES} ${uifiles})

#qt5_use_modules(WorldsParticle OpenGL)
#qt5_use_modules(WorldsParticle Widgets)

target_link_libraries(WorldsParticle ${QT_QTMAIN_LIBRARY} ${QT_LIBRARIES}
    ${OPENGL_LIBRARIES} Qt5::Widgets Qt5::Core Qt5::OpenGL ${ASSIMP_LIBRARIES}
    ${DevIL_LIBRARY_ILUT} ${DevIL_LIBRARY_ILU} ${DevIL_LIBRARY_IL} ${GLEW_LIBRARY})
