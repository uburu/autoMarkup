project(auto-markup-tests)

find_package (Boost COMPONENTS unit_test_framework REQUIRED)

include_directories(fakeit)

SET(CMAKE_EXE_LINKER_FLAGS="-fprofile-arcs -ftest-coverage")

set(MARKUP_TESTS_SRC
        markup/main.cpp
        markup/test_markup.hpp
        markup/test_markup_factory.hpp
        markup/test_cos_words_comparator.hpp
        markup/test_sentence_sum_convolution.hpp)

add_executable(markup_tests ${MARKUP_TESTS_SRC})
target_link_libraries(markup_tests auto_markup_app ${Boost_LIBRARIES} gcov)
add_test(NAME markup-test COMMAND markup_tests)
