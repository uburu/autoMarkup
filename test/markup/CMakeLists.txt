project(markup-tests)

set(TEST_MARKUP_INC
        test_markup.hpp
        test_markup_factory.hpp
        test_cos_words_comparator.hpp
        test_sentence_sum_convolution.hpp)

add_executable(markup-tests ${TEST_MARKUP_INC} main.cpp)
target_link_libraries(markup-tests ${Boost_LIBRARIES} markup)
add_test(NAME markup-test COMMAND markup-tests)