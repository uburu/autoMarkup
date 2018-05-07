project(auto-markup-app)

set(AUTO_MARKUP_APP_INC
        ../inc/common/types.hpp
        ../inc/markup/markup.hpp
        ../inc/markup/sequential_markup.hpp
        ../inc/markup/vectorized_words_comparator.hpp
        ../inc/markup/cos_vectorized_words_comparator.hpp)

set(AUTO_MARKUP_APP_SRC
        main.cpp
        markup/markup.cpp
        markup/sequential_markup.cpp
        markup/cos_vectorized_words_comparator.cpp)

add_library(auto_markup_app STATIC ${AUTO_MARKUP_APP_INC} ${AUTO_MARKUP_APP_SRC})