cmake_minimum_required(VERSION 3.6.0)

set(CMAKE_CXX_STANDARD 17)

add_executable(automarkup
        autoMarkup/main.cpp
        autoMarkup/dataStructs.hpp
        autoMarkup/dataStructs.cpp
        autoMarkup/DataHub/DataHub.hpp
        autoMarkup/DataHub/DataHub.cpp
        autoMarkup/Tokenizer/Tokenizer.hpp
        autoMarkup/Tokenizer/Tokenizer.cpp
        autoMarkup/DictHandler/DictHandler.hpp
        autoMarkup/DictHandler/DictHandler.cpp
        autoMarkup/Markup/Markup.hpp
        autoMarkup/Markup/Markup.cpp)

add_executable(tests
        tests/main.cpp)