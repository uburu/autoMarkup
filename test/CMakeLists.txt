project(auto-markup-tests)

find_package (Boost COMPONENTS unit_test_framework REQUIRED)

include_directories(fakeit)
add_subdirectory(markup)
