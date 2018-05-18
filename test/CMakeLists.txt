project(auto-markup-tests)

set(Boost_USE_STATIC_LIBS on)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

include_directories(fakeit)

add_subdirectory(markup)
