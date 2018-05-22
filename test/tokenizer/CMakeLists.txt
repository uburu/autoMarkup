cmake_minimum_required(VERSION 3.5)
project(tokenizer_test)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        ../../inc/datahub
        ../../inc/datastructs
        ../../inc/lemmatization
        ../../inc/tokenizer
        ../../inc/controller
        ../../inc/baker
        )

set(HEADERS
        ../../inc/datahub/DataHub.hpp
        ../../inc/datahub/DataHubBuilder.hpp
        ../../inc/controller/controller.hpp
        ../../inc/datastructs/dataStructs.hpp
        ../../inc/tokenizer/Tokenizer.hpp
        ../../inc/lemmatization/wordnet.hpp
        ../../inc/lemmatization/filemanager.hpp
        ../../inc/lemmatization/traindataparser.hpp
        ../../inc/lemmatization/traincontroller.hpp
        ../../inc/lemmatization/lemmatization.hpp
        ../../inc/baker/baker.hpp
        )

set(SOURCES
        ../../src/datahub/DataHub.cpp
        ../../src/datahub/DataHubBuilder.cpp
        ../../src/controller/controller.cpp
        ../../src/datastructs/dataStructs.cpp
        ../../src/tokenizer/Tokenizer.cpp
        ../../src/lemmatization/wordnet.cpp
        ../../src/lemmatization/filemanager.cpp
        ../../src/lemmatization/traindataparser.cpp
        ../../src/lemmatization/traincontroller.cpp
        ../../src/lemmatization/lemmatization.cpp
        ../../src/baker/baker.cpp
        Tokenizer_tests.cpp
        )

add_executable(tokenizer_test ${SOURCES} ${HEADERS})