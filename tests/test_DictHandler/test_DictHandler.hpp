#include <iostream>
#include <assert.h>
#include <boost/test/minimal.hpp>
#include "../../autoMarkup/DataHub/DataHub.hpp"
#include "../../autoMarkup/DictHandler/DictHandler.hpp"

#define PATH "../data/tests/" // path to data


void test_DictHandler_fillDict_1()
{
    std::ifstream file;
    std::string path = PATH;
    path += "dict.txt"; /// file name
    file.open(path); 
    
    DictHandler dict;
    dict.fillDict(file, " ", ",");
    file.close();
    
    BOOST_REQUIRE(dict.getId("привет") == 1);
}


void test_DictHandler_fillDict_2()
{
    std::ifstream file;
    std::string path = PATH;
    path += "dict.txt"; /// file name
    file.open(path); 
    
    DictHandler dict;
    dict.fillDict(file, " ", ",");
    file.close();
    
    BOOST_REQUIRE(dict.getId("нет") == 0);
}
