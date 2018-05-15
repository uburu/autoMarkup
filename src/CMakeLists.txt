project(auto-markup-app)

set(COMMON_INC
        ../inc/common/types.hpp
        ../inc/common/exceptions.hpp
        ../inc/common/not_implemented_exception.hpp)

set(MARKUP_INC
        ../inc/markup/markup.hpp
        ../inc/markup/abstract_markup_factory.hpp
        ../inc/markup/markup_factory.hpp
        ../inc/markup/sequential_markup.hpp
        ../inc/markup/fast_markup.hpp
        ../inc/markup/words_comparator.hpp
        ../inc/markup/cos_words_comparator.hpp
        ../inc/markup/sentence_convolution.hpp
        ../inc/markup/sentence_sum_convolution.hpp)

set(MARKUP_SRC
        markup/markup_factory.cpp
        markup/cos_words_comparator.cpp
        markup/sentence_sum_convolution.cpp)

set(AUTO_MARKUP_INC
        ${COMMON_INC}
        ${MARKUP_INC})

set(AUTO_MARKUP_SRC
        main.cpp
        ${MARKUP_SRC})

add_library(auto_markup_app STATIC ${AUTO_MARKUP_INC} ${AUTO_MARKUP_SRC})
target_link_libraries(auto_markup_app ${CMAKE_THREAD_LIBS_INIT})