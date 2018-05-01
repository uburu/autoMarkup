cmake_minimum_required(VERSION 3.5)
project(tokenize_test)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        Tokenizer_tests.cpp
        ../../autoMarkup/dataStructs.hpp
        ../../autoMarkup/dataStructs.cpp
        ../../autoMarkup/DataHub/DataHub.hpp
        ../../autoMarkup/DataHub/DataHub.cpp
        ../../autoMarkup/Tokenizer/Tokenizer.hpp
        ../../autoMarkup/Tokenizer/Tokenizer.cpp
        Tokenizer_tests.cpp
        )
add_executable(tokenize_test ${SOURCE_FILES})