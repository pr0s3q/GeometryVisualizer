cmake_minimum_required(VERSION 4.1)
project(GeometryVisualizer LANGUAGES CXX)

set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

# C++ standard
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect sources under src/
# CONFIGURE_DEPENDS makes CMake re-run configure when files are added/removed.
set(SRC_DIR "${CMAKE_CURRENT_LIST_DIR}/src")
file(GLOB SRC_FILES CONFIGURE_DEPENDS
        "${SRC_DIR}/*.cpp"
)

if (NOT SRC_FILES)
        message(FATAL_ERROR "No .cpp files found under ${SRC_DIR}")
endif()

add_subdirectory(3rd-party/raylib)

# Create executable
add_executable(GeometryVisualizer
        main.cpp
        ${SRC_FILES}
)

# Optimization & CPU flags
target_compile_options(GeometryVisualizer PRIVATE
#        -Wall -Wextra -Wpedantic
#        -Wshadow -Wconversion -Wsign-conversion
#        -Werror

        $<$<CONFIG:Release>:-O3 -march=native -mavx2>

        $<$<CONFIG:Debug>:-O0 -g -fsanitize=address,undefined,leak -fno-omit-frame-pointer>
)

target_link_options(GeometryVisualizer PRIVATE
        $<$<CONFIG:Debug>:-fsanitize=address,undefined,leak>
)

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_include_directories(GeometryVisualizer SYSTEM PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/3rd-party/raygui/src"
)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

target_compile_options(raylib PRIVATE
        -Wno-error=sign-conversion
)

# For executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)  # default fallback

# Use per-configuration directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin/Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_BINARY_DIR}/bin/RelWithDebInfo)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${CMAKE_BINARY_DIR}/bin/MinSizeRel)

# For static and shared libraries
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib/Debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib/Release)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib/Debug)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib/Release)

set_target_properties(GeometryVisualizer PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin/Debug
        RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin/Release
)
