cmake_minimum_required(VERSION 3.15)

# 
project(Flux VERSION 1.0.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Ensures you stick to standard C++, not compiler-specific extensions

# Define your source files (Update this list as you add new .cpp files)
# NOTE: Avoid using GLOB (wildcards) as it can miss new files unless you re-run CMake manually.
set(SOURCES
    src/main.cpp
    src/server.cpp
    src/threadpool.cpp
)

# Create the Executable
# This tells CMake to create a binary named "flux_server" from your sources
add_executable(flux_server ${SOURCES})

# Best Practice: Enable compiler warnings to catch bugs early
if(MSVC)
    target_compile_options(flux_server PRIVATE /W4)
else()
    target_compile_options(flux_server PRIVATE -Wall -Wextra -Wpedantic)
endif()

# (Optional) If you later use threads on Linux, you might need this:
find_package(Threads REQUIRED)
target_link_libraries(flux_server PRIVATE Threads::Threads)