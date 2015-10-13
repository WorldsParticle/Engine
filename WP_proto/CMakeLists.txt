################################################################################
# \file CMakeLists.txt
# \brief CMakeLists used to generate worldparticles program.
# \author Martin-Pierrat Louis (mart_p)
# \version 1.0.0
# \date October 13, 2015
################################################################################


## CMAKE INITIALISATION

PROJECT(WORLD_PARTICLES)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/cmake_modules")

## END CMAKE INITIALISATION



## PROJECT VERSION

SET(WORLD_PARTICLES_VERSION_MAJOR 1)
SET(WORLD_PARTICLES_VERSION_MINOR 0)
SET(WORLD_PARTICLES_VERSION_PATCH 0)
SET(WORLD_PARTICLES_VERSION_EXTRA 0)

SET(WORLD_PARTICLES_VERSION)
SET(WORLD_PARTICLES_VERSION_FULL)

CONFIGURE_FILE(
    "${CMAKE_SOURCE_DIR}/sources/worldparticles.hpp.in"
    "${CMAKE_SOURCE_DIR}/sources/worldparticles.hpp"
    )

## END PROJECT VERSION



## PROJECT LANGUAGE

ENABLE_LANGUAGE(CXX)

## END PROJECT LANGUAGE



## FIND LIBRARY DEPENDENCY

FIND_PACKAGE(Qt5Core REQUIRED QtWindow)
FIND_PACKAGE(Qt5Widgets REQUIRED)
FIND_PACKAGE(Qt5OpenGL REQUIRED)
FIND_PACKAGE(OpenGL REQUIRED)
FIND_PACKAGE(Devil REQUIRED)
FIND_PACKAGE(Assimp REQUIRED)

## END FIND LIBRARY DEPENDENCY



## QT CONFIGURATION

SET(CMAKE_AUTORCC ON)
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTOUIC ON)
SET(QT_USE_QTOPENGL TRUE)
ADD_DEFINITIONS(${QT_DEFINITIONS})

## END QT CONFIGURATION



## PROJECT SOURCES FILES

SET(WORLD_PARTICLES_SOURCES_FILES
    ${CMAKE_SOURCE_DIR}/sources/main.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/gameclock.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/gameengine.cpp
    ${CMAKE_SOURCE_DIR}/sources/graphic/myglpainter.cpp
    ${CMAKE_SOURCE_DIR}/sources/model/model.cpp
    ${CMAKE_SOURCE_DIR}/sources/model/tools.cpp
    ${CMAKE_SOURCE_DIR}/sources/window/glwidget.cpp
    ${CMAKE_SOURCE_DIR}/sources/window/glwindow.cpp
    ${CMAKE_SOURCE_DIR}/sources/window/irrlichtwidget.cpp
    ${CMAKE_SOURCE_DIR}/sources/window/mainwindow.cpp
    ${CMAKE_SOURCE_DIR}/sources/window/toolwidget.cpp
    ${CMAKE_SOURCE_DIR}/sources/graphic/AssimpProgressHandlerOverload.cpp
    ${CMAKE_SOURCE_DIR}/sources/graphic/GPUBuffer.cpp
    ${CMAKE_SOURCE_DIR}/sources/graphic/material.cpp
    ${CMAKE_SOURCE_DIR}/sources/graphic/mesh.cpp
    ${CMAKE_SOURCE_DIR}/sources/graphic/texture.cpp
    )

## END PROJECT SOURCES FILES



## PROJECT HEADERS FILES

SET(WORLD_PARTICLES_HEADERS_FILES
    sources/main.h
    sources/engine/gameclock.h
    sources/engine/gameengine.h
    sources/graphic/myglpainter.h
    sources/model/model.h
    sources/model/tools.h
    sources/window/glwidget.h
    sources/window/glwindow.h
    sources/window/irrlichtwidget.h
    sources/window/mainwindow.h
    sources/window/toolwidget.h
    sources/graphic/AssimpProgressHandlerOverload.h
    sources/graphic/GPUBuffer.h
    sources/graphic/material.h
    sources/graphic/mesh.h
    sources/graphic/texture.h
    )

## END PROJECT HEADERS FILES



## PROJECT INCLUDES DIRECTORIES

SET(WORLD_PARTICLES_INCLUDE_DIR
    ${CMAKE_SOURCE_DIR}/sources
    ${CMAKE_SOURCE_DIR}/sources/graphic
    ${CMAKE_SOURCE_DIR}/sources/model
    ${CMAKE_SOURCE_DIR}/sources/window
    ${CMAKE_SOURCE_DIR}/sources/engine
    ${CMAKE_BINARY_DIR}
    )

INCLUDE_DIRECTORIES(
    ${WORLD_PARTICLES_INCLUDE_DIR}
    ${QT_QTOPENGL_INCLUDE_DIR}
    ${OPENGL_INCLUDE_DIR}
    ${ASSIMP_INCLUDE_DIR}
    ${DevIL_INCLUDE_DIR}
    )

## END PROJECT INCLUDES DIRECTORIES



## PROJECT SETTINGS

ADD_EXECUTABLE(WorldsParticle
    ${WORLD_PARTICLES_SOURCES_FILES}
    ${WORLD_PARTICLES_QT_GUI_FILES}
    )

TARGET_LINK_LIBRARIES(WorldsParticle
    ${QT_QTMAIN_LIBRARY}
    ${QT_LIBRARIES}
    ${OPENGL_LIBRARIES}
    Qt5::Widgets
    Qt5::Core
    Qt5::OpenGL
    ${ASSIMP_LIBRARY}
    ${DevIL_LIBRARY_ILUT}
    ${DevIL_LIBRARY_ILU}
    ${DevIL_LIBRARY_IL}
    )

## END PROJECT SETTINGS



## DOXYGEN CONFIGURATION

FIND_PACKAGE(Doxygen QUIET)

IF (DOXYGEN_FOUND)

#    CONFIGURE_FILE(
        #${CMAKE_SOURCE_DIR}/Doxyfile.in
        #${CMAKE_BINARY_DIR}/Doxyfile
        #@ONLY)

    #ADD_CUSTOM_TARGET(doc
        #${DOXYGEN_EXECUTABLE} ${CMAKE_BINARY_DIR}/Doxyfile
        #WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/sources"
        #COMMENT "Generating API documentation with Doxygen" VERBATIM
        #)

ENDIF (DOXYGEN_FOUND)

## END DOXYGEN CONFIGURATION

#if (WIN32)
    #if (MSVC)
    #elseif(CMAKE_COMPILER_IS_GNUCXX)
	## SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows")
	## # Not tested
    #else()
	#message(SEND_ERROR "You are using an
	#unsupported Windows compiler! (Not MSVC or GCC)")
    #endif()
#elseif (UNIX)
    #set(CMAKE_PREFIX_PATH "/usr/lib64/qt5")
    SET(CMAKE_CXX_FLAGS "-std=c++0x")
#else ()
    #message(SEND_ERROR "You are on an unsupported platform! (Not Win32 or Unix)")
#ENDIF ()


