cmake_minimum_required(VERSION 3.27)
project(CPong)

set(CMAKE_CXX_STANDARD 17)

# Main executable
add_executable(CPong
        src/Main.cpp
        src/Engine/Core/HardwareInfo.cpp
        src/Engine/Core/PlatformDetection.cpp
        src/Engine/Core/Logger.cpp
        src/Engine/Window/Window.cpp
        src/Engine/Renderer/Renderer.cpp
        src/Engine/Input/Input.cpp
        src/Engine/Audio/Audio.cpp
        src/Game/Game.cpp
        src/Game/Paddle/Paddle.cpp
        src/Game/Ball/Ball.cpp
        src/Game/Player/Player.cpp
        src/Game/AI/AI.cpp
)

# Specify include directories for the main executable
target_include_directories(CPong PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)

# Tests
add_executable(CPongTests
        tests/WindowTests.cpp
        src/Engine/Window/Window.cpp
        src/Engine/Renderer/Renderer.cpp
)

# Specify include directories for the test executable
target_include_directories(CPongTests PRIVATE ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
