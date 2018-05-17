project(auto-markup-test-markup)

set(TEST_MARKUP_SRC
        main.cpp
        test_markup.hpp
        test_markup_factory.hpp
        test_cos_words_comparator.hpp
        test_sentence_sum_convolution.hpp)

add_executable(markup_tests ${TEST_MARKUP_SRC})
target_link_libraries(markup_tests ${Boost_LIBRARIES} auto_markup_lib)
add_test(NAME markup-test COMMAND markup_tests)