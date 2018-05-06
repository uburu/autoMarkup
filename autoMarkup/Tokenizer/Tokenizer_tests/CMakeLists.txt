cmake_minimum_required(VERSION 3.5)
project(tokenize_test)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        ../../dataStructs.hpp
        ../../dataStructs.cpp
        ../../DataHub/DataHub.hpp
        ../../DataHub/DataHub.cpp
        ../Tokenizer.hpp
        ../Tokenizer.cpp
        ../../lemmatization/wordnet.hpp
        ../../lemmatization/wordnet.cpp
        ../../lemmatization/filemanager.hpp
        ../../lemmatization/filemanager.cpp
        ../../lemmatization/traindataparser.hpp
        ../../lemmatization/traindataparser.cpp
        ../../lemmatization/traincontroller.hpp
        ../../lemmatization/traincontroller.cpp
        ../../lemmatization/utf8/checked.hpp
        ../../lemmatization/utf8/unchecked.hpp
        ../../lemmatization/utf8/core.hpp
        ../../lemmatization/utf8.hpp
        Tokenizer_tests.cpp
        )
add_executable(tokenize_test ${SOURCE_FILES})
