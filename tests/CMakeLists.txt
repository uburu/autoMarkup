cmake_minimum_required(VERSION 3.6.0)
# project(autoMarkup)

set(CMAKE_CXX_STANDARD 14)

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
