cmake_minimum_required(VERSION 3.6.0)
# project(autoMarkup)

set(CMAKE_CXX_STANDARD 14)

# Locate GTest
find_package(Boost REQUIRED)


set(SOURCE_FILES
        autoMarkup/dataStructs.hpp
        autoMarkup/dataStructs.cpp
        autoMarkup/DataHub/DataHub.hpp
        autoMarkup/DataHub/DataHub.cpp
        autoMarkup/DictHandler/DictHandler.hpp
        autoMarkup/DictHandler/DictHandler.cpp
        
        example.cpp
        )


add_executable(example ${SOURCE_FILES})
