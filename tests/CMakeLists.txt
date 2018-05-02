cmake_minimum_required(VERSION 3.6.0)

set(CMAKE_CXX_STANDARD 17)

add_library(tests STATIC
        DataHub/DataHubTests.hpp
        DataHub/DataHubTests.cpp
        Tokenizer/TokenizerTests.hpp
        Tokenizer/TokenizerTests.cpp
        DictHandler/DictHandlerTests.hpp
        DictHandler/DictHandlerTests.hpp
        Markup/MakupTests.hpp
        Markup/MakupTests.cpp)