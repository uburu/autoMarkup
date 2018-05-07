cmake_minimum_required(VERSION 3.6.0)

set(CMAKE_CXX_STANDARD 17)

include_directories(autoMarkup tests)

set(PROJECT_FILES
        autoMarkup/dataStructs.hpp
        autoMarkup/DataHub/DataHub.hpp
        autoMarkup/DataHub/DataHub.cpp
        autoMarkup/Tokenizer/Tokenizer.hpp
        autoMarkup/Tokenizer/Tokenizer.cpp
        autoMarkup/DictHandler/DictHandler.hpp
        autoMarkup/DictHandler/DictHandler.cpp
        autoMarkup/Markup/Types.hpp
        autoMarkup/Markup/Markup.hpp
        autoMarkup/Markup/Markup.cpp
        autoMarkup/Markup/SequentialMarkup.hpp
        autoMarkup/Markup/SequentialMarkup.cpp
        autoMarkup/Markup/CosCounter.hpp
        autoMarkup/Markup/CosCounter.cpp)

set(TEST_FILES)

add_executable(automarkup main.cpp ${PROJECT_FILES})
add_executable(automarkuptests tests.cpp ${PROJECT_FILES})
