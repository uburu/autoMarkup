cmake_minimum_required(VERSION 3.6.0)

set(CMAKE_CXX_STANDARD 17)

include_directories(autoMarkup tests)

add_executable(automarkup main.cpp)
add_subdirectory(autoMarkup)
target_link_libraries(automarkup automarkuplib)

add_executable(automarkuptests tests.cpp)
add_subdirectory(tests)
target_link_libraries(automarkuptests tests)
