cmake_minimum_required(VERSION 3.6.0)

set(CMAKE_CXX_STANDARD 17)

add_library(automarkuplib STATIC
        dataStructs.hpp
        DataHub/DataHub.hpp
        DataHub/DataHub.cpp
        Tokenizer/Tokenizer.hpp
        Tokenizer/Tokenizer.cpp
        DictHandler/DictHandler.hpp
        DictHandler/DictHandler.cpp
        Markup/Markup.hpp
        Markup/Markup.cpp)