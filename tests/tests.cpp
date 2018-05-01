#include <iostream>
#include <assert.h>
#include "../autoMarkup/DataHub/DataHub.hpp"

#define PATH "../data/" // path to data

void test_DataHub_ReadText_1()
{
	std::ifstream file;
    std::string path = PATH;
    path += "sents.txt"; /// file name
    file.open(path); 
    
    DataHub dh;
    dh.ReadText(file);
    file.close();
    
    std::string tmp_str;
    tmp_str = "привет, кек. как дела? хорошо а у тебя?";

    assert(dh.getText() == tmp_str);
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
    
    std::string tmp_str;
    tmp_str = "привет";

    assert(dh.getDict()[0].word == tmp_str);
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
    
    std::string tmp_str;
    tmp_str = "тебя";
    
    assert(dh.getDict()[6].word == tmp_str);
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
    
    assert(dh.getDict()[0].id == 1);
}


int main(int argc, const char * argv[]) {

    test_DataHub_ReadText_1();
    test_DataHub_ReadDict_1();
    test_DataHub_ReadDict_2();
    test_DataHub_ReadDict_3();
    
    
    return 0;
}
