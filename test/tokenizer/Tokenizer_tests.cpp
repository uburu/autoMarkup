#include "DataHub.hpp"
#include "DataHubBuilder.hpp"
#include "Tokenizer.hpp"
#include "lemmatization.hpp"
#include "traincontroller.hpp"
#include "controller.hpp"
#include <iostream>
#include <fstream>


int main()
{
	std::ifstream fin("test_text.txt");

	Controller controller;
	std::shared_ptr<DataHub> hubObj = controller.AllocateHub();

	Tokenizer t; // токенизация текста
	controller.SetOperation(&t, hubObj);
	controller.ConstructHub(fin);

	Lemmatizator l; // приведение слов к нормальной форме
	controller.SetOperation(&l, hubObj);
	controller.ConstructHub();

	hubObj->ShowContent();

	return 0;
}
