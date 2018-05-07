project(auto-markup-tests)

find_package (Boost COMPONENTS unit_test_framework REQUIRED)

set(MARKUP_TESTS_SRC
        markup/test_markup.cpp)

add_executable(markup_tests ${MARKUP_TESTS_SRC})
target_link_libraries(markup_tests ${Boost_LIBRARIES} auto_markup_app)
add_test(NAME markup-test COMMAND markup_tests)

