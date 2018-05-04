cmake_minimum_required(VERSION 3.6.0)

set(CMAKE_CXX_STANDARD 17)

set (APP_FILES
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
        autoMarkup/Markup/CosCounter.hpp
        autoMarkup/Markup/CosCounter.cpp)

set(TEST_FILES
        tests/test_DataHub/test_DataHub.hpp
        tests/Tokenizer_tests/Tokenizer_tests.cpp
        tests/test_DictHandler/test_DictHandler.hpp)

find_package(Boost REQUIRED)

add_executable(example example.cpp ${APP_FILES})
add_executable(automarkup_tests tests.cpp ${APP_FILES} ${TEST_FILES})

