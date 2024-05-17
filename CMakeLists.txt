cmake_minimum_required(VERSION 3.27)
project(GameLib)

set(CMAKE_CXX_STANDARD 23)

add_executable(GameLib main.cpp
        glad.c
        gameEngine/ShaderCollection.cpp
        gameEngine/ShaderCollection.h
        gameEngine/Shader.cpp
        gameEngine/Shader.h
        stb_image.cpp
        stb_image.h
        gameEngine/Texture.cpp
        gameEngine/Texture.h
        gameEngine/RenderManager.cpp
        gameEngine/RenderManager.h
        gameEngine/Entity.cpp
        gameEngine/Entity.h
        gameEngine/Component.cpp
        gameEngine/Component.h
        gameEngine/GameManager.cpp
        gameEngine/GameManager.h
        gameEngine/inputManager.cpp
        gameEngine/inputManager.h
        gameEngine/vector2.cpp
        gameEngine/vector2.h
        gameEngine/Components/Spin.cpp
        gameEngine/Components/Spin.h
        gameEngine/Components/CameraControl.cpp
        gameEngine/Components/CameraControl.h
        gameEngine/Components/RenderComponent.cpp
        gameEngine/Components/RenderComponent.h
        gameEngine/Window.cpp
        gameEngine/Window.h
        gameEngine/VectorMethods.cpp
        gameEngine/VectorMethods.h
        gameEngine/ObjectPool.cpp
        gameEngine/ObjectPool.h
)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")
add_subdirectory("glfw-3.3.9")
target_link_libraries(GameLib glfw)
target_link_libraries(GameLib "${CMAKE_CURRENT_SOURCE_DIR}/lib/opengl32.lib")