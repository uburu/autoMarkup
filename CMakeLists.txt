cmake_minimum_required(VERSION 3.6.0)
project(auto-markup)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
    ${PROJECT_BINARY_DIR}/bin
    CACHE PATH
    "Single Directory for all")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${PROJECT_BINARY_DIR}/bin
    CACHE PATH
    "Single Directory for all")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
    ${PROJECT_BINARY_DIR}/lib
    CACHE PATH
    "Single Directory for all")

enable_testing()

find_package (Threads REQUIRED)
find_package(Boost REQUIRED)

include_directories(inc)
add_subdirectory(src build/src)
add_subdirectory(test build/test)
