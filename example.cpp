#include <iostream>
#include "autoMarkup/DataHub/DataHub.hpp"
#include "autoMarkup/DictHandler/DictHandler.hpp"


int main(int argc, const char * argv[]) {
   
    std::ifstream file;
    file.open("./data/sents.txt");
    
    DataHub dh;
    dh.ReadText(file);
    file.close();

    std::cout << dh.getText() << std::endl;


    file.open("./data/dict.txt");
    
    DictHandler dict;
    dict.fillDict(file, " ", ",");
    file.close();
    

    std::cout << dict.getId("привет") << std::endl;
    
    
    return 0;
}
