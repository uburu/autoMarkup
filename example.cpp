#include <iostream>
#include "autoMarkup/DataHub/DataHub.hpp"


int main(int argc, const char * argv[]) {
   
    std::ifstream file;
    file.open("/Users/nikita/bmstu/technopark/sem_1/cpp_project/autoMarkup/autoMarkup/data/sents.txt");
    
    DataHub dh;
    dh.ReadText(file);
    file.close();

    std::cout << dh.getText() << std::endl;


    
    
    
    return 0;
}
