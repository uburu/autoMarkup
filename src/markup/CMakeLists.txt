project(markup)

set(MARKUP_INC
        ../../inc/markup/markup.hpp
        ../../inc/markup/abstract_markup_factory.hpp
        ../../inc/markup/markup_factory.hpp
        ../../inc/markup/sequential_markup.hpp
        ../../inc/markup/fast_markup.hpp
        ../../inc/markup/words_comparator.hpp
        ../../inc/markup/cos_words_comparator.hpp
        ../../inc/markup/sentence_convolution.hpp
        ../../inc/markup/sentence_sum_convolution.hpp)

set(MARKUP_SRC
        markup_factory.cpp
        cos_words_comparator.cpp
        sentence_sum_convolution.cpp)

add_library(markup STATIC ${MARKUP_INC} ${MARKUP_SRC})
target_link_libraries(markup ${CMAKE_THREAD_LIBS_INIT})
