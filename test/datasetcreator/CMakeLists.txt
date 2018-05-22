cmake_minimum_required(VERSION 3.5)
project(creator_test)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        ../../inc/datahub
        ../../inc/datastructs
        ../../inc/lemmatization
        ../../inc/tokenizer
        ../../inc/controller
        ../../inc/baker
        ../../inc/datasetcreator
        ../../inc/dict_handler
        ../../inc/common
        ../../inc
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
        ../../inc/datasetcreator/datasetcreator.hpp
        ../../inc/dict_handler/dict_handler.hpp
        ../../inc/dict_handler/model.hpp
        ../../inc/common/types.hpp
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
        ../../src/datasetcreator/datasetcreator.cpp
        ../../src/dict_handler/dict_handler.cpp
        ../../src/markup/cos_words_comparator.cpp
        ../../src/markup/markup_factory.cpp
        ../../src/markup/sentence_sum_convolution.cpp
        datasetcreatorTest.cpp
        )

add_executable(creator_test ${SOURCES} ${HEADERS})