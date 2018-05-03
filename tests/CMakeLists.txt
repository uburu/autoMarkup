cmake_minimum_required(VERSION 3.6.0)

set(CMAKE_CXX_STANDARD 17)

<<<<<<< HEAD
# Locate GTest
find_package(Boost REQUIRED)


set(SOURCE_FILES
        tests.cpp
        ../autoMarkup/dataStructs.hpp
        ../autoMarkup/dataStructs.cpp
        ../autoMarkup/DataHub/DataHubErrors.hpp
        ../autoMarkup/DictHandler/DictHandlerErrors.hpp
        ../autoMarkup/DataHub/DataHub.hpp
        ../autoMarkup/DataHub/DataHub.cpp
        ../autoMarkup/DictHandler/DictHandler.hpp
        ../autoMarkup/DictHandler/DictHandler.cpp

        test_DataHub/test_DataHub.hpp
        test_DictHandler/test_DictHandler.hpp
        
        tests.cpp
        )


add_executable(tests ${SOURCE_FILES})
=======
add_library(tests STATIC
        DataHub/DataHubTests.hpp
        DataHub/DataHubTests.cpp
        Tokenizer/TokenizerTests.hpp
        Tokenizer/TokenizerTests.cpp
        DictHandler/DictHandlerTests.hpp
        DictHandler/DictHandlerTests.hpp
        Markup/MakupTests.hpp
        Markup/MakupTests.cpp)
>>>>>>> show
