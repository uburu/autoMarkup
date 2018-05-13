project(auto-markup-tests)

find_package (Boost COMPONENTS unit_test_framework REQUIRED)

include_directories(fakeit)

set(MARKUP_TESTS_SRC
        markup/main.cpp
        markup/test_markup.hpp
        markup/test_markup_factory.hpp
        markup/test_cos_words_comparator.hpp
        markup/test_sentence_sum_convolution.hpp)

add_executable(markup_tests ${MARKUP_TESTS_SRC})
target_link_libraries(markup_tests ${Boost_LIBRARIES} auto_markup_app)
add_test(NAME markup-test COMMAND markup_tests)
