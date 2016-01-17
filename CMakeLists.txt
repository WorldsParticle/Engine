#
# \file CMakeLists.txt
#
# \brief CMakeLists used to generate worldparticles program.
#
# \author Martin-Pierrat Louis (mart_p)
#
# \version 1.0.0
#
# \date October 13, 2015
#



## CMAKE INITIALISATION

PROJECT(Engine)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/cmake_modules")

## END CMAKE INITIALISATION



## PROJECT VERSION

SET(ENGINE_VERSION_MAJOR 2)
SET(ENGINE_VERSION_MINOR 0)
SET(ENGINE_VERSION_PATCH 0)
SET(ENGINE_VERSION_EXTRA 0)

SET(ENGINE_VERSION ${WORLD_PARTICLES_VERSION_MAJOR}.${WORLD_PARTICLES_VERSION_MINOR}.${WORLD_PARTICLES_VERSION_PATCH})
SET(ENGINE_VERSION_FULL ${WORLD_PARTICLES_VERSION}.${WORLD_PARTICLES_VERSION_EXTRA})

SET(RESOURCES_PATH "${CMAKE_SOURCE_DIR}/resources")

CONFIGURE_FILE(
    "${CMAKE_SOURCE_DIR}/sources/version.hpp.in"
    "${CMAKE_SOURCE_DIR}/sources/version.hpp"
    )

CONFIGURE_FILE(
    "${CMAKE_SOURCE_DIR}/sources/configuration.hpp.in"
    "${CMAKE_SOURCE_DIR}/sources/configuration.hpp"
    )

## END PROJECT VERSION



## PROJECT LANGUAGE

ENABLE_LANGUAGE(CXX)

## END PROJECT LANGUAGE



## FIND LIBRARY DEPENDENCY

FIND_PACKAGE(OpenGL REQUIRED)
FIND_PACKAGE(GLEW REQUIRED)
FIND_PACKAGE(Devil REQUIRED)
FIND_PACKAGE(Assimp REQUIRED)
FIND_PACKAGE(Log4cpp REQUIRED)
FIND_PACKAGE(RapidXml REQUIRED)

## END FIND LIBRARY DEPENDENCY


## PROJECT SOURCES FILES

SET(WORLD_PARTICLES_SOURCES_FILES
    ${CMAKE_SOURCE_DIR}/sources/Animation/Animation.cpp
    ${CMAKE_SOURCE_DIR}/sources/AnimationLibrary/AnimationLibrary.cpp
    ${CMAKE_SOURCE_DIR}/sources/ArrayObject/ArrayObject.cpp
    ${CMAKE_SOURCE_DIR}/sources/AssimpImporter/AssimpImporter.cpp
    ${CMAKE_SOURCE_DIR}/sources/AssimpScene/AssimpScene.cpp
    ${CMAKE_SOURCE_DIR}/sources/BufferObject/BufferObject.cpp
    ${CMAKE_SOURCE_DIR}/sources/Camera/Camera.cpp
    ${CMAKE_SOURCE_DIR}/sources/Entity/Entity.cpp
    ${CMAKE_SOURCE_DIR}/sources/GameEngine/GameEngine.cpp
    ${CMAKE_SOURCE_DIR}/sources/Light/Light.cpp
    ${CMAKE_SOURCE_DIR}/sources/Material/Material.cpp
    ${CMAKE_SOURCE_DIR}/sources/MaterialLibrary/MaterialLibrary.cpp
    ${CMAKE_SOURCE_DIR}/sources/Mesh/Mesh.cpp
    ${CMAKE_SOURCE_DIR}/sources/MeshLibrary/MeshLibrary.cpp
    ${CMAKE_SOURCE_DIR}/sources/Object/Object.cpp
    ${CMAKE_SOURCE_DIR}/sources/PerspectiveCamera/PerspectiveCamera.cpp
    ${CMAKE_SOURCE_DIR}/sources/Renderer/Renderer.cpp
    ${CMAKE_SOURCE_DIR}/sources/Scene/Scene.cpp
    ${CMAKE_SOURCE_DIR}/sources/SceneGraph/SceneGraph.cpp
    ${CMAKE_SOURCE_DIR}/sources/SceneGraphNode/SceneGraphNode.cpp
    ${CMAKE_SOURCE_DIR}/sources/Shader/Shader.cpp
    ${CMAKE_SOURCE_DIR}/sources/ShaderLibrary/ShaderLibrary.cpp
    ${CMAKE_SOURCE_DIR}/sources/ShaderProgram/ShaderProgram.cpp
    ${CMAKE_SOURCE_DIR}/sources/ShaderProgramLibrary/ShaderProgramLibrary.cpp
    ${CMAKE_SOURCE_DIR}/sources/SpatialGraph/SpatialGraph.cpp
    ${CMAKE_SOURCE_DIR}/sources/Texture/Texture.cpp
    ${CMAKE_SOURCE_DIR}/sources/TextureLibrary/TextureLibrary.cpp
    ${CMAKE_SOURCE_DIR}/sources/Transform/Transform.cpp
    )

## END PROJECT SOURCES FILES



## PROJECT HEADERS FILES

SET(WORLD_PARTICLES_HEADERS_FILES

    ${CMAKE_SOURCE_DIR}/sources/Animation/Animation.hpp
    ${CMAKE_SOURCE_DIR}/sources/AnimationLibrary/AnimationLibrary.hpp
    ${CMAKE_SOURCE_DIR}/sources/ArrayObject/ArrayObject.hpp
    ${CMAKE_SOURCE_DIR}/sources/AssimpImporter/AssimpImporter.hpp
    ${CMAKE_SOURCE_DIR}/sources/AssimpScene/AssimpScene.hpp
    ${CMAKE_SOURCE_DIR}/sources/BufferObject/BufferObject.hpp
    ${CMAKE_SOURCE_DIR}/sources/Camera/Camera.hpp
    ${CMAKE_SOURCE_DIR}/sources/Entity/Entity.hpp
    ${CMAKE_SOURCE_DIR}/sources/GameEngine/GameEngine.hpp
    ${CMAKE_SOURCE_DIR}/sources/Library/Library.hpp
    ${CMAKE_SOURCE_DIR}/sources/Light/Light.hpp
    ${CMAKE_SOURCE_DIR}/sources/Material/Material.hpp
    ${CMAKE_SOURCE_DIR}/sources/MaterialLibrary/MaterialLibrary.hpp
    ${CMAKE_SOURCE_DIR}/sources/Mesh/Mesh.hpp
    ${CMAKE_SOURCE_DIR}/sources/MeshLibrary/MeshLibrary.hpp
    ${CMAKE_SOURCE_DIR}/sources/Object/Object.hpp
    ${CMAKE_SOURCE_DIR}/sources/PerspectiveCamera/PerspectiveCamera.hpp
    ${CMAKE_SOURCE_DIR}/sources/Renderer/Renderer.hpp
    ${CMAKE_SOURCE_DIR}/sources/Scene/Scene.hpp
    ${CMAKE_SOURCE_DIR}/sources/SceneGraph/SceneGraph.hpp
    ${CMAKE_SOURCE_DIR}/sources/SceneGraphNode/SceneGraphNode.hpp
    ${CMAKE_SOURCE_DIR}/sources/Shader/Shader.hpp
    ${CMAKE_SOURCE_DIR}/sources/ShaderLibrary/ShaderLibrary.hpp
    ${CMAKE_SOURCE_DIR}/sources/ShaderProgram/ShaderProgram.hpp
    ${CMAKE_SOURCE_DIR}/sources/ShaderProgramLibrary/ShaderProgramLibrary.hpp
    ${CMAKE_SOURCE_DIR}/sources/SpatialGraph/SpatialGraph.hpp
    ${CMAKE_SOURCE_DIR}/sources/Texture/Texture.hpp
    ${CMAKE_SOURCE_DIR}/sources/TextureLibrary/TextureLibrary.hpp
    ${CMAKE_SOURCE_DIR}/sources/Transform/Transform.hpp
    )

## END PROJECT HEADERS FILES



## PROJECT INCLUDES DIRECTORIES

SET(WORLD_PARTICLES_INCLUDE_DIR
    ${CMAKE_SOURCE_DIR}/sources/Animation/
    ${CMAKE_SOURCE_DIR}/sources/AnimationLibrary/
    ${CMAKE_SOURCE_DIR}/sources/ArrayObject/
    ${CMAKE_SOURCE_DIR}/sources/AssimpImporter/
    ${CMAKE_SOURCE_DIR}/sources/AssimpScene/
    ${CMAKE_SOURCE_DIR}/sources/BufferObject/
    ${CMAKE_SOURCE_DIR}/sources/Camera/
    ${CMAKE_SOURCE_DIR}/sources/Entity/
    ${CMAKE_SOURCE_DIR}/sources/GameClock/
    ${CMAKE_SOURCE_DIR}/sources/GameEngine/
    ${CMAKE_SOURCE_DIR}/sources/Library/
    ${CMAKE_SOURCE_DIR}/sources/Light/
    ${CMAKE_SOURCE_DIR}/sources/Material/
    ${CMAKE_SOURCE_DIR}/sources/MaterialLibrary/
    ${CMAKE_SOURCE_DIR}/sources/Mesh/
    ${CMAKE_SOURCE_DIR}/sources/MeshLibrary/
    ${CMAKE_SOURCE_DIR}/sources/Object/
    ${CMAKE_SOURCE_DIR}/sources/PerspectiveCamera/
    ${CMAKE_SOURCE_DIR}/sources/Renderer/
    ${CMAKE_SOURCE_DIR}/sources/Scene/
    ${CMAKE_SOURCE_DIR}/sources/SceneGraph/
    ${CMAKE_SOURCE_DIR}/sources/SceneGraphNode/
    ${CMAKE_SOURCE_DIR}/sources/Shader/
    ${CMAKE_SOURCE_DIR}/sources/ShaderLibrary/
    ${CMAKE_SOURCE_DIR}/sources/ShaderProgram/
    ${CMAKE_SOURCE_DIR}/sources/ShaderProgramLibrary/
    ${CMAKE_SOURCE_DIR}/sources/Shaders/
    ${CMAKE_SOURCE_DIR}/sources/SpatialGraph/
    ${CMAKE_SOURCE_DIR}/sources/Texture/
    ${CMAKE_SOURCE_DIR}/sources/TextureLibrary/
    ${CMAKE_SOURCE_DIR}/sources/Transform/
    ${CMAKE_SOURCE_DIR}/sources/
    )

INCLUDE_DIRECTORIES(
    ${WORLD_PARTICLES_INCLUDE_DIR}
    ${OPENGL_INCLUDE_DIR}
    ${GLEW_INCLUDE_DIRS}
    ${ASSIMP_INCLUDE_DIR}
    ${DevIL_INCLUDE_DIR}
    ${LOG4CPP_INCLUDE_DIR}
    )

## END PROJECT INCLUDES DIRECTORIES



## PROJECT SETTINGS

ADD_LIBRARY(WorldsParticle ${WORLD_PARTICLES_SOURCES_FILES})

TARGET_LINK_LIBRARIES(WorldsParticle
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
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


