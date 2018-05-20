#include "../inc/dict_handler/dict_handler.hpp"
#include "controller.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include "DataHub.hpp"


int main(int argc, char **argv)
{
	std::ifstream fin("dict.txt");

	Controller controller;
	std::shared_ptr<DataHub> hubObj = controller.AllocateHub();

	DictHandler dict;


	controller.SetOperation(&dict, hubObj);
	controller.ConstructHub(fin);

	std::cout << hubObj->dict[1].word << std::endl;

	std::cout << hubObj->dict[1].vec.size() << std::endl;


    return 0;
}
