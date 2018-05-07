project(auto-markup-tests)

find_package (Boost COMPONENTS unit_test_framework REQUIRED)

set(MARKUP_TESTS_SRC
        markup/main.cpp
        markup/test_markup.hpp
        markup/test_cos_vectorized_words_comparator.hpp)
add_executable(markup_tests ${MARKUP_TESTS_SRC})
target_link_libraries(markup_tests ${Boost_LIBRARIES} auto_markup_app)
add_test(NAME markup-test COMMAND markup_tests)

