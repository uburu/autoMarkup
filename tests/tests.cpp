#include <iostream>
#include "../autoMarkup/DataHub/DataHub.hpp"

#define PATH "autoMarkup/autoMarkup/data/" // path to data

bool test_DataHub_ReadText_1()
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

    return dh.getText() == tmp_str;
}


bool test_DataHub_ReadDict_1()
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

    return dh.getDict()[0].word == tmp_str;
}


bool test_DataHub_ReadDict_2()
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
    
    return dh.getDict()[6].word == tmp_str;
}


bool test_DataHub_ReadDict_3()
{
    std::ifstream file;
    std::string path = PATH;
    path += "dict.txt"; /// file name
    file.open(path); 
    
    DataHub dh;
    dh.ReadDict(file, " ", ",");
    file.close();
    
    return dh.getDict()[0].id == 1;
}


int main(int argc, const char * argv[]) {
   
    if (!test_DataHub_ReadText_1())
    {
    	std::cout << "test_DataHub_ReadText_1 failed\n";
    }
    else
    	std::cout << "Ok  – test_DataHub_ReadText_1\n";

    if (!test_DataHub_ReadDict_1())
    {
        std::cout << "test_DataHub_ReadDict_1 failed\n";
    }
    else
        std::cout << "Ok  – test_DataHub_ReadDict_1\n";

    if (!test_DataHub_ReadDict_2())
    {
        std::cout << "test_DataHub_ReadDict_2 failed\n";
    }
    else
        std::cout << "Ok  – test_DataHub_ReadDict_2\n";

    if (!test_DataHub_ReadDict_3())
    {
        std::cout << "test_DataHub_ReadDict_3 failed\n";
    }
    else
        std::cout << "Ok  – test_DataHub_ReadDict_3\n";
    
    
    
    return 0;
}
