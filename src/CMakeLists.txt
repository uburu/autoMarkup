project(auto-markup-app)

add_subdirectory(common)
add_subdirectory(markup)

add_library(auto_markup_lib)
target_link_libraries(auto_markup_lib
        auto_markup_markup)

add_executable(auto_markup main.cpp)
target_link_libraries(auto_markup
        auto_markup_lib)
