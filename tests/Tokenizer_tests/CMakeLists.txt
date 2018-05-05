cmake_minimum_required(VERSION 3.5)
project(tokenize_test)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        ../../autoMarkup/dataStructs.hpp
        ../../autoMarkup/dataStructs.cpp
        ../../autoMarkup/DataHub/DataHub.hpp
        ../../autoMarkup/DataHub/DataHub.cpp
        ../../autoMarkup/Tokenizer/Tokenizer.hpp
        ../../autoMarkup/Tokenizer/Tokenizer.cpp
        ../../autoMarkup/lemmatization/wordnet.hpp
		../../autoMarkup/lemmatization/wordnet.cpp
		../../autoMarkup/lemmatization/filemanager.hpp
		../../autoMarkup/lemmatization/filemanager.cpp
		../../autoMarkup/lemmatization/traindataparser.hpp
		../../autoMarkup/lemmatization/traindataparser.cpp
        ../../autoMarkup/lemmatization/traincontroller.hpp
        ../../autoMarkup/lemmatization/traincontroller.cpp
        ../../autoMarkup/lemmatization/utf8/checked.hpp
		../../autoMarkup/lemmatization/utf8/unchecked.hpp
		../../autoMarkup/lemmatization/utf8/core.hpp
		../../autoMarkup/lemmatization/utf8.hpp
        Tokenizer_tests.cpp
        )
add_executable(tokenize_test ${SOURCE_FILES})
