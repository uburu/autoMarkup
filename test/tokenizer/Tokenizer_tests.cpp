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



	Traincontroller ac("../../data/Lemmadict.txt"); // заполняем префиксное дерево
	ac.run();

	// приведение слов к нормальной форме
	Lemmatizator l(ac.wordnetObj); // через конструктор передаем объект дерева
	controller.SetOperation(&l, hubObj);
	controller.ConstructHub();

	hubObj->ShowContent();

	return 0;
}
