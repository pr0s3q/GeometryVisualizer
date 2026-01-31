cmake_minimum_required(VERSION 4.1)
project(GeometryVisualizer LANGUAGES CXX)

set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

# Use clang++
set(CMAKE_CXX_COMPILER clang++)

# C++ standard (adjust if needed)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
        ${CMAKE_BINARY_DIR}/bin/Release/GeometryVisualizer
)

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
        -O2
        -march=native
        -mavx2
        -Wall
        -Wno-missing-braces
        -Wno-unused-result
)

# Preprocessor definitions
target_compile_definitions(GeometryVisualizer PRIVATE
        _DEFAULT_SOURCE
        PLATFORM_DESKTOP
        PLATFORM_DESKTOP_GLFW
)

# Include directories
target_include_directories(GeometryVisualizer PRIVATE
        include
        .
        /home/cristopher/git/C/raylib/src
        /home/cristopher/git/C/raylib/src/external
        /usr/local/include
)

# Library search paths
target_link_directories(GeometryVisualizer PRIVATE
        .
        /home/cristopher/git/C/raylib/src
        /usr/local/lib
)

# Link libraries
target_link_libraries(GeometryVisualizer PRIVATE
        raylib
        GL
        m
        pthread
        dl
        rt
        X11
        atomic
)
