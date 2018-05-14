cmake_minimum_required(VERSION 3.5)
project(tokenize_test)

set(CMAKE_CXX_STANDARD 14)

include_directories(
        ../../lemmatization/include
        ../include
        ../../DataHub/include
        ../../include
        )


set(HEADERS
        ../../include/dataStructs.hpp
        ../../DataHub/include/DataHub.hpp
        ../include/Tokenizer.hpp
        ../../lemmatization/include/wordnet.hpp
        ../../lemmatization/include/filemanager.hpp
        ../../lemmatization/include/traindataparser.hpp
        ../../lemmatization/include/traincontroller.hpp
        )

set(SOURCES
        ../../src/dataStructs.cpp
        ../../DataHub/src/DataHub.cpp
        ../src/Tokenizer.cpp
        ../../lemmatization/src/wordnet.cpp
        ../../lemmatization/src/filemanager.cpp
        ../../lemmatization/src/traindataparser.cpp
        ../../lemmatization/src/traincontroller.cpp
        Tokenizer_tests.cpp
        )

add_executable(tokenize_test ${SOURCES} ${HEADERS})
