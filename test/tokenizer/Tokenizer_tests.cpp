#include "DataHub.hpp"
#include "DataHubBuilder.hpp"
#include "Tokenizer.hpp"
#include "traincontroller.hpp"
#include "controller.hpp"
#include <iostream>
#include <fstream>


int main()
{

	std::ifstream fin("test_text.txt");
	Controller controller;
	Tokenizer t;
	controller.SetOperation(&t);
	controller.ConstructHub(fin);
	std::shared_ptr<DataHub> fullHub = controller.GetHub();
	fullHub->ShowContent();

	return 0;
}
