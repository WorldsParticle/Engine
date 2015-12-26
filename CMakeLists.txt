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
FIND_PACKAGE(Log4cpp REQUIRED)
FIND_PACKAGE(RapidXml REQUIRED)

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

    ${CMAKE_SOURCE_DIR}/sources/engine/Animation/Animation.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/AnimationLibrary/AnimationLibrary.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/AssimpImporter/AssimpImporter.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/AssimpScene/AssimpScene.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Camera/Camera.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Entity/Entity.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/GameEngine/GameEngine.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Light/Light.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Material/Material.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/MaterialLibrary/MaterialLibrary.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Mesh/Mesh.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/MeshLibrary/MeshLibrary.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Object/Object.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/PerspectiveCamera/PerspectiveCamera.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/RenderGraph/RenderGraph.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Scene/Scene.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/SceneGraph/SceneGraph.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/SceneGraphNode/SceneGraphNode.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Texture/Texture.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/TextureLibrary/TextureLibrary.cpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Transform/Transform.cpp

    ${CMAKE_SOURCE_DIR}/sources/model/model.cpp
    ${CMAKE_SOURCE_DIR}/sources/model/tools.cpp

    ${CMAKE_SOURCE_DIR}/sources/window/glwidget.cpp
    ${CMAKE_SOURCE_DIR}/sources/window/glwindow.cpp
    ${CMAKE_SOURCE_DIR}/sources/window/mainwindow.cpp
    ${CMAKE_SOURCE_DIR}/sources/window/toolwidget.cpp

    ${CMAKE_SOURCE_DIR}/sources/main.cpp
    )

## END PROJECT SOURCES FILES



## PROJECT HEADERS FILES

SET(WORLD_PARTICLES_HEADERS_FILES

    ${CMAKE_SOURCE_DIR}/sources/engine/Animation/Animation.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/AnimationLibrary/AnimationLibrary.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/AssimpImporter/AssimpImporter.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/AssimpScene/AssimpScene.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Camera/Camera.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Entity/Entity.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/GameEngine/GameEngine.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Library/Library.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Light/Light.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Material/Material.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/MaterialLibrary/MaterialLibrary.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Mesh/Mesh.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/MeshLibrary/MeshLibrary.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Object/Object.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/PerspectiveCamera/PerspectiveCamera.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/RenderGraph/RenderGraph.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Scene/Scene.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/SceneGraph/SceneGraph.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/SceneGraphNode/SceneGraphNode.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Texture/Texture.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/TextureLibrary/TextureLibrary.hpp
    ${CMAKE_SOURCE_DIR}/sources/engine/Transform/Transform.hpp


    ${CMAKE_SOURCE_DIR}/sources/model/model.h
    ${CMAKE_SOURCE_DIR}/sources/model/tools.h

    ${CMAKE_SOURCE_DIR}/sources/window/glwidget.h
    ${CMAKE_SOURCE_DIR}/sources/window/glwindow.h
    ${CMAKE_SOURCE_DIR}/sources/window/mainwindow.h
    ${CMAKE_SOURCE_DIR}/sources/window/toolwidget.h

    ${CMAKE_SOURCE_DIR}/sources/worldparticles.hpp

    )

## END PROJECT HEADERS FILES



## PROJECT INCLUDES DIRECTORIES

SET(WORLD_PARTICLES_INCLUDE_DIR

    ${CMAKE_SOURCE_DIR}/sources/engine/Animation/
    ${CMAKE_SOURCE_DIR}/sources/engine/AnimationLibrary/
    ${CMAKE_SOURCE_DIR}/sources/engine/AssimpImporter/
    ${CMAKE_SOURCE_DIR}/sources/engine/AssimpScene/
    ${CMAKE_SOURCE_DIR}/sources/engine/Camera/
    ${CMAKE_SOURCE_DIR}/sources/engine/Entity/
    ${CMAKE_SOURCE_DIR}/sources/engine/GameEngine/
    ${CMAKE_SOURCE_DIR}/sources/engine/Library/
    ${CMAKE_SOURCE_DIR}/sources/engine/Light/
    ${CMAKE_SOURCE_DIR}/sources/engine/Material/
    ${CMAKE_SOURCE_DIR}/sources/engine/MaterialLibrary/
    ${CMAKE_SOURCE_DIR}/sources/engine/Mesh/
    ${CMAKE_SOURCE_DIR}/sources/engine/MeshLibrary/
    ${CMAKE_SOURCE_DIR}/sources/engine/Object/
    ${CMAKE_SOURCE_DIR}/sources/engine/PerspectiveCamera/
    ${CMAKE_SOURCE_DIR}/sources/engine/RenderGraph/
    ${CMAKE_SOURCE_DIR}/sources/engine/Scene/
    ${CMAKE_SOURCE_DIR}/sources/engine/SceneGraph/
    ${CMAKE_SOURCE_DIR}/sources/engine/SceneGraphNode/
    ${CMAKE_SOURCE_DIR}/sources/engine/Texture/
    ${CMAKE_SOURCE_DIR}/sources/engine/TextureLibrary/
    ${CMAKE_SOURCE_DIR}/sources/engine/Transform/

    ${CMAKE_SOURCE_DIR}/sources/model
    ${CMAKE_SOURCE_DIR}/sources/window
    ${CMAKE_SOURCE_DIR}/sources

    ${CMAKE_BINARY_DIR}
    )

INCLUDE_DIRECTORIES(
    ${WORLD_PARTICLES_INCLUDE_DIR}
    ${QT_QTOPENGL_INCLUDE_DIR}
    ${OPENGL_INCLUDE_DIR}
    ${ASSIMP_INCLUDE_DIR}
    ${DevIL_INCLUDE_DIR}
    ${LOG4CPP_INCLUDE_DIR}
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
    ${LOG4CPP_LIBRARY}
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
    SET(CMAKE_CXX_FLAGS "-std=c++14 -W -Wall -Wextra")
#else ()
    #message(SEND_ERROR "You are on an unsupported platform! (Not Win32 or Unix)")
#ENDIF ()


