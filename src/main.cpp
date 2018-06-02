#include "dict_handler.hpp"
#include "controller.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include "DataHub.hpp"


int main(int argc, char **argv)
{

	if (argc != 2)
	{
		std::cout << "No w2v dictionary found!\n";
		return -1;
	}

	std::string filename(argv[1]);

	std::ifstream fin(filename);

	Controller controller;
	std::shared_ptr<DataHub> hubObj = controller.AllocateHub();

	DictHandler dict;


	controller.SetOperation(&dict, hubObj);
	controller.ConstructHub(fin);
	
    return 0;
}
