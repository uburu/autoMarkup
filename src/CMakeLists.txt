project(auto-markup-app)

add_subdirectory(common)
add_subdirectory(markup)

add_executable(automarkup main.cpp)
target_link_libraries(automarkup
        markup)
