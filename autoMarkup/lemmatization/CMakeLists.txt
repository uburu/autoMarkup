cmake_minimum_required(VERSION 3.5)
project(lemma)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
		wordnet.hpp
		wordnet.cpp
		filemanager.hpp
		filemanager.cpp
		traindataparser.hpp
		traindataparser.cpp
        traincontroller.hpp
        traincontroller.cpp
        utf8/checked.hpp
		utf8/unchecked.hpp
		utf8/core.hpp
		utf8.hpp
        main.cpp
        )
add_executable(lemma_test ${SOURCE_FILES})