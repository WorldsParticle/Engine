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

SET(WORLD_PARTICLES_VERSION ${WORLD_PARTICLES_VERSION_MAJOR}.${WORLD_PARTICLES_VERSION_MINOR}.${WORLD_PARTICLES_VERSION_PATCH})
SET(WORLD_PARTICLES_VERSION_FULL ${WORLD_PARTICLES_VERSION}.${WORLD_PARTICLES_VERSION_EXTRA})

SET(RESOURCES_PATH "${CMAKE_SOURCE_DIR}/resources")

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

    ${CMAKE_SOURCE_DIR}/sources/engine/GameClock/GameClock.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/GameEngine/GameEngine.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/GameObject/GameObject.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/GameView/GameView.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Renderer/Renderer.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Renderer/CubeRenderer/CubeRenderer.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Camera/Camera.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Transform/Transform.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Cube/Cube.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Material/Material.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Mesh/Mesh.cpp

    ${CMAKE_SOURCE_DIR}/sources/graphic/myglpainter.cpp
    ${CMAKE_SOURCE_DIR}/sources/model/model.cpp
    ${CMAKE_SOURCE_DIR}/sources/model/tools.cpp
    ${CMAKE_SOURCE_DIR}/sources/window/glwidget.cpp
    ${CMAKE_SOURCE_DIR}/sources/window/glwindow.cpp
    ${CMAKE_SOURCE_DIR}/sources/window/mainwindow.cpp
    ${CMAKE_SOURCE_DIR}/sources/window/toolwidget.cpp
    ${CMAKE_SOURCE_DIR}/sources/graphic/AssimpProgressHandlerOverload.cpp

    )

## END PROJECT SOURCES FILES



## PROJECT HEADERS FILES

SET(WORLD_PARTICLES_HEADERS_FILES
    ${CMAKE_SOURCE_DIR}/sources/main.h

    ${CMAKE_SOURCE_DIR}/sources/engine/GameClock/GameClock.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/GameEngine/GameEngine.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/GameObject/GameObject.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/GameView/GameView.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Renderer/Renderer.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Renderer/CubeRenderer/CubeRenderer.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Camera/Camera.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Transform/Transform.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Cube/Cube.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Material/Material.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Mesh/Mesh.hpp


    ${CMAKE_SOURCE_DIR}/sources/graphic/myglpainter.h
    ${CMAKE_SOURCE_DIR}/sources/model/model.h
    ${CMAKE_SOURCE_DIR}/sources/model/tools.h
    ${CMAKE_SOURCE_DIR}/sources/window/glwidget.h
    ${CMAKE_SOURCE_DIR}/sources/window/glwindow.h
    ${CMAKE_SOURCE_DIR}/sources/window/mainwindow.h
    ${CMAKE_SOURCE_DIR}/sources/window/toolwidget.h
    ${CMAKE_SOURCE_DIR}/sources/graphic/AssimpProgressHandlerOverload.h

    )

## END PROJECT HEADERS FILES



## PROJECT INCLUDES DIRECTORIES

SET(WORLD_PARTICLES_INCLUDE_DIR
    ${CMAKE_SOURCE_DIR}/sources
    ${CMAKE_SOURCE_DIR}/sources/graphic
    ${CMAKE_SOURCE_DIR}/sources/model
    ${CMAKE_SOURCE_DIR}/sources/window
    ${CMAKE_SOURCE_DIR}/sources/engine
    ${CMAKE_SOURCE_DIR}/sources/engine/GameClock
    ${CMAKE_SOURCE_DIR}/sources/engine/GameEngine
    ${CMAKE_SOURCE_DIR}/sources/engine/GameObject
    ${CMAKE_SOURCE_DIR}/sources/engine/GameView
    ${CMAKE_SOURCE_DIR}/sources/engine/Renderer
    ${CMAKE_SOURCE_DIR}/sources/engine/Renderer/CubeRenderer/
    ${CMAKE_SOURCE_DIR}/sources/engine/Camera/
    ${CMAKE_SOURCE_DIR}/sources/engine/Transform/
    ${CMAKE_SOURCE_DIR}/sources/engine/Cube/
    ${CMAKE_SOURCE_DIR}/sources/engine/Material/
    ${CMAKE_SOURCE_DIR}/sources/engine/Mesh/
    ${CMAKE_BINARY_DIR}
    )

INCLUDE_DIRECTORIES(
    ${WORLD_PARTICLES_INCLUDE_DIR}
    ${QT_QTOPENGL_INCLUDE_DIR}
    ${OPENGL_INCLUDE_DIR}
    ${ASSIMP_INCLUDE_DIR}
    ${DevIL_INCLUDE_DIR}
    "C:/Program Files (x86)/glm/include"
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

    CONFIGURE_FILE(
        ${CMAKE_SOURCE_DIR}/Doxyfile.in
        ${CMAKE_BINARY_DIR}/Doxyfile
        @ONLY)

    ADD_CUSTOM_TARGET(doc
        ${DOXYGEN_EXECUTABLE} ${CMAKE_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/sources"
        COMMENT "Generating API documentation with Doxygen" VERBATIM
        )

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


