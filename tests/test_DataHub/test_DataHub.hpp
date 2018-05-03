#include <iostream>
#include <assert.h>
#include <boost/test/minimal.hpp>
#include "../../autoMarkup/DataHub/DataHub.hpp"
#include "../../autoMarkup/DictHandler/DictHandler.hpp"

#define PATH "../data/tests/" // path to data

void test_DataHub_ReadText_1()
{
	std::ifstream file;
    std::string path = PATH;
    path += "sents.txt"; /// file name
    file.open(path); 
    
    DataHub dh;
    dh.ReadText(file);
    file.close();

    BOOST_REQUIRE(dh.getText() == "привет, кек. как дела? хорошо а у тебя?");
}


void test_DataHub_ReadDict_1()
{
    std::ifstream file;
    std::string path = PATH;
    path += "dict.txt"; /// file name
    file.open(path); 
    
    DataHub dh;
    dh.ReadDict(file, " ", ",");
    file.close();
    
    BOOST_CHECK(dh.getDict()[0].word == "привет");
}


void test_DataHub_ReadDict_2()
{
    std::ifstream file;
    std::string path = PATH;
    path += "dict.txt"; /// file name
    file.open(path); 
    
    DataHub dh;
    dh.ReadDict(file, " ", ",");
    file.close();
    
    BOOST_CHECK(dh.getDict()[6].word == "тебя");
}


void test_DataHub_ReadDict_3()
{
    std::ifstream file;
    std::string path = PATH;
    path += "dict.txt"; /// file name
    file.open(path); 
    
    DataHub dh;
    dh.ReadDict(file, " ", ",");
    file.close();
    
    BOOST_REQUIRE(dh.getDict()[0].id == 1);
}
