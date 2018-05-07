project(auto-markup-app)

set(AUTO_MARKUP_APP_INC
        ../inc/common/types.hpp
        ../inc/markup/types.hpp
        ../inc/markup/markup.hpp
        ../inc/markup/sequential_markup.hpp)

set(AUTO_MARKUP_APP_SRC
        main.cpp
        markup/markup.cpp
        markup/sequential_markup.cpp)

add_library(auto_markup_app STATIC ${AUTO_MARKUP_APP_INC} ${AUTO_MARKUP_APP_SRC})