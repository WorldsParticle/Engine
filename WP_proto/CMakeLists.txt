# TODO


SET(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_modules")


cmake_minimum_required( VERSION 2.8.11 )
set (QT_USE_QTOPENGL TRUE)
find_package (Qt5Core REQUIRED QtWindow)
find_package (Qt5Widgets REQUIRED)
find_package (Qt5OpenGL REQUIRED)
find_package (OpenGL REQUIRED)
find_package (Assimp REQUIRED)
find_package(Devil REQUIRED)
#find_package (GLEW REQUIRED)
#INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})
qt5_wrap_ui(uifiles window/mainwindow.ui window/toolwidget.ui)
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/graphic ${CMAKE_CURRENT_SOURCE_DIR}/model
    ${CMAKE_CURRENT_SOURCE_DIR}/window ${CMAKE_CURRENT_SOURCE_DIR}/engine
    ${QT_QTOPENGL_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${ASSIMP_INCLUDE_DIR}
    ${DevIL_INCLUDE_DIR})#${GLEW_INCLUDE_PATH})
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#find_package(SFML REQUIRED system window graphics network audio)
# The QUIET option disables messages if the package cannot be found. 
FIND_PACKAGE(Qt5Widgets)

SET(SOURCES
    main.cpp
    engine/gameclock.cpp
    engine/gameengine.cpp
    graphic/myglpainter.cpp
    model/model.cpp
    model/tools.cpp
    window/glwidget.cpp
    window/glwindow.cpp
    window/irrlichtwidget.cpp
    window/mainwindow.cpp
    window/toolwidget.cpp
    graphic/AssimpProgressHandlerOverload.cpp
    graphic/GPUBuffer.cpp
    graphic/material.cpp
    graphic/mesh.cpp
    graphic/texture.cpp
)

SET(HEADERS
    main.h
    engine/gameclock.h
    engine/gameengine.h
    graphic/myglpainter.h
    model/model.h
    model/tools.h
    window/glwidget.h
    window/glwindow.h
    window/irrlichtwidget.h
    window/mainwindow.h
    window/toolwidget.h
    graphic/AssimpProgressHandlerOverload.h
    graphic/GPUBuffer.h
    graphic/material.h
    graphic/mesh.h
    graphic/texture.h
)

add_executable(WorldsParticle ${SOURCES} ${uifiles})



LINK_DIRECTORIES("F:/libs/assimp/lib64/")

if (WIN32) # Check if we are on Windows
    if (MSVC) # Check if we are using the Visual Studio compiler
	#set_target_properties(WorldsParticle PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")
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

#qt5_use_modules(WorldsParticle OpenGL)
#qt5_use_modules(WorldsParticle Widgets)

target_link_libraries(WorldsParticle
    ${QT_QTMAIN_LIBRARY}
    ${QT_LIBRARIES}
    ${OPENGL_LIBRARIES}
    Qt5::Widgets
    Qt5::Core
    Qt5::OpenGL
    ${ASSIMP_LIBRARIES}
    ${DevIL_LIBRARY_ILUT}
    ${DevIL_LIBRARY_ILU}
    ${DevIL_LIBRARY_IL}
    )

message(${DevIL_LIBRARY_ILUT})
message(${DevIL_LIBRARY_ILU})
message(${DevIL_LIBRARY_IL})

# ${GLEW_LIBRARY})
