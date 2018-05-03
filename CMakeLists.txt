cmake_minimum_required(VERSION 3.6.0)
# project(autoMarkup)

set(CMAKE_CXX_STANDARD 14)


add_executable(example example.cpp 
autoMarkup/DataHub/DataHub.hpp autoMarkup/DataHub/DataHub.cpp
autoMarkup/dataStructs.hpp autoMarkup/dataStructs.cpp)
