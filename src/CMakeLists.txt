project(auto-markup-app)

set(COMMON_INC
        ../inc/common/types.hpp)

set(MARKUP_INC
        ../inc/markup/markup.hpp
        ../inc/markup/markup_factory.hpp
        ../inc/markup/sequential_markup.hpp
        ../inc/markup/vectorized_words_comparator.hpp
        ../inc/markup/cos_vectorized_words_comparator.hpp)

set(MARKUP_SRC
        markup/markup.cpp
        markup/sequential_markup.cpp
        markup/cos_vectorized_words_comparator.cpp)

set(AUTO_MARKUP_INC
        ${COMMON_INC}
        ${MARKUP_INC})

set(AUTO_MARKUP_SRC
        main.cpp
        ${MARKUP_SRC})

add_library(auto_markup_app STATIC ${AUTO_MARKUP_INC} ${AUTO_MARKUP_SRC})