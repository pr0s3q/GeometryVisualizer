cmake_minimum_required(VERSION 4.1)
project(GeometryVisualizer LANGUAGES CXX)

set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

# C++ standard
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(3rd-party/raylib)

# Collect sources under src/
# CONFIGURE_DEPENDS makes CMake re-run configure when files are added/removed.
set(SRC_DIR "${CMAKE_CURRENT_LIST_DIR}/src")
file(GLOB SRC_FILES CONFIGURE_DEPENDS
        "${SRC_DIR}/*.cpp"
)

if (NOT SRC_FILES)
        message(FATAL_ERROR "No .cpp files found under ${SRC_DIR}")
endif()

# Create executable
add_executable(GeometryVisualizer
        main.cpp
        ${SRC_FILES}
)

# Optimization & CPU flags
target_compile_options(GeometryVisualizer PRIVATE
        -O3
        -march=native
        -mavx2
        -Wall
        -Wno-missing-braces
        -Wno-unused-result
)

target_include_directories(${PROJECT_NAME} PUBLIC
        include
        "${CMAKE_CURRENT_SOURCE_DIR}/3rd-party/raylib/src"
        "${CMAKE_CURRENT_SOURCE_DIR}/3rd-party/raygui/src"
)

target_link_directories(GeometryVisualizer PRIVATE
        .
        /3rd-party/raylib/src
)

target_link_libraries(${PROJECT_NAME} PUBLIC raylib)

# Output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
        ${CMAKE_BINARY_DIR}/bin/Release/GeometryVisualizer
)
