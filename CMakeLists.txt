#
# \file CMakeLists.txt
#
# \author Martin-Pierrat Louis (mart_p)
#
# \date Sat, 16 Jan 2016 20:31:02
#
# \version 1.0.0
#
# CMakeList used to generate the Engine library.
#


## CMAKE INITIALISATION

PROJECT(Engine)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.12)
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/cmake_modules")

## END CMAKE INITIALISATION



## PROJECT VERSION

SET(PROJECT_VERSION_MAJOR 2)
SET(PROJECT_VERSION_MINOR 1)
SET(PROJECT_VERSION_PATCH 0)
SET(PROJECT_VERSION_EXTRA 0)

SET(PROJECT_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})
SET(PROJECT_VERSION_FULL ${PROJECT_VERSION}.${PROJECT_VERSION_EXTRA})

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

SET(PROJECT_SOURCES_DIR ${CMAKE_SOURCE_DIR}/sources/)

SET(PROJECT_SOURCES_FILES

    ${CMAKE_SOURCE_DIR}/sources/Animation/Animation.cpp
    ${CMAKE_SOURCE_DIR}/sources/AnimationLibrary/AnimationLibrary.cpp
    ${CMAKE_SOURCE_DIR}/sources/ArrayObject/ArrayObject.cpp
    ${CMAKE_SOURCE_DIR}/sources/AssimpImporter/AssimpImporter.cpp
    ${CMAKE_SOURCE_DIR}/sources/AssimpScene/AssimpScene.cpp
    ${CMAKE_SOURCE_DIR}/sources/BufferObject/BufferObject.cpp
    ${CMAKE_SOURCE_DIR}/sources/Camera/Camera.cpp
    ${CMAKE_SOURCE_DIR}/sources/Clock/Clock.cpp
    ${CMAKE_SOURCE_DIR}/sources/Entity/Entity.cpp
    ${CMAKE_SOURCE_DIR}/sources/Engine/Engine.cpp
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



## PROJECT INCLUDES DIRECTORIES

SET(PROJECT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/)

INCLUDE_DIRECTORIES(
    ${PROJECT_INCLUDE_DIR}
    ${OPENGL_INCLUDE_DIR}
    ${GLEW_INCLUDE_DIRS}
    ${ASSIMP_INCLUDE_DIR}
    ${DevIL_INCLUDE_DIR}
    ${LOG4CPP_INCLUDE_DIR}
    )

## END PROJECT INCLUDES DIRECTORIES



## PROJECT HEADERS FILES

SET(PROJECT_TEMPLATE_FILES
    ${PROJECT_INCLUDE_DIR}/Library.tpp
    )

SET(PROJECT_HEADERS_FILES

    ${PROJECT_INCLUDE_DIR}/Animation.hpp
    ${PROJECT_INCLUDE_DIR}/AnimationLibrary.hpp
    ${PROJECT_INCLUDE_DIR}/ArrayObject.hpp
    ${PROJECT_INCLUDE_DIR}/AssimpImporter.hpp
    ${PROJECT_INCLUDE_DIR}/AssimpScene.hpp
    ${PROJECT_INCLUDE_DIR}/BufferObject.hpp
    ${PROJECT_INCLUDE_DIR}/Camera.hpp
    ${PROJECT_INCLUDE_DIR}/Clock.hpp
    ${PROJECT_INCLUDE_DIR}/Entity.hpp
    ${PROJECT_INCLUDE_DIR}/Engine.hpp
    ${PROJECT_INCLUDE_DIR}/Library.hpp
    ${PROJECT_INCLUDE_DIR}/Light.hpp
    ${PROJECT_INCLUDE_DIR}/Material.hpp
    ${PROJECT_INCLUDE_DIR}/MaterialLibrary.hpp
    ${PROJECT_INCLUDE_DIR}/Mesh.hpp
    ${PROJECT_INCLUDE_DIR}/MeshLibrary.hpp
    ${PROJECT_INCLUDE_DIR}/Object.hpp
    ${PROJECT_INCLUDE_DIR}/PerspectiveCamera.hpp
    ${PROJECT_INCLUDE_DIR}/Renderer.hpp
    ${PROJECT_INCLUDE_DIR}/Scene.hpp
    ${PROJECT_INCLUDE_DIR}/SceneGraph.hpp
    ${PROJECT_INCLUDE_DIR}/SceneGraphNode.hpp
    ${PROJECT_INCLUDE_DIR}/Shader.hpp
    ${PROJECT_INCLUDE_DIR}/ShaderLibrary.hpp
    ${PROJECT_INCLUDE_DIR}/ShaderProgram.hpp
    ${PROJECT_INCLUDE_DIR}/ShaderProgramLibrary.hpp
    ${PROJECT_INCLUDE_DIR}/SpatialGraph.hpp
    ${PROJECT_INCLUDE_DIR}/Texture.hpp
    ${PROJECT_INCLUDE_DIR}/TextureLibrary.hpp
    ${PROJECT_INCLUDE_DIR}/Transform.hpp

    ${PROJECT_TEMPLATE_FILES}

    )

## END PROJECT HEADERS FILES



## PROJECT SETTINGS

IF (CMAKE_BUILD_TYPE MATCHES "debug")

    SET(CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG} -D__DEBUG__)
    SET(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/debug/)

ELSE ()

    SET(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/release)

ENDIF ()

## END PROJECT SETTINGS



## COMPILATION SETTINGS

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

## END COMPILATION SETTINGS



## BINARY SETTINGS

ADD_LIBRARY(${CMAKE_PROJECT_NAME} SHARED ${PROJECT_SOURCES_FILES})

## END BINARY SETTINGS



## LIBRARY SETTINGS

TARGET_LINK_LIBRARIES(${CMAKE_PROJECT_NAME}
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${ASSIMP_LIBRARY}
    ${LOG4CPP_LIBRARY}
    ${DevIL_LIBRARY_ILUT}
    ${DevIL_LIBRARY_ILU}
    ${DevIL_LIBRARY_IL}
    )

## END LIBRARY SETTINGS



## INSTALLATION SETTINGS

INSTALL(TARGETS ${CMAKE_PROJECT_NAME}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)

INSTALL(FILES ${PROJECT_HEADERS_FILES}
    DESTINATION include/${CMAKE_PROJECT_NAME}
    )

## END INSTALLATION SETTINGS



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
