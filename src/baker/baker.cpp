#include "baker.hpp"

void Baker::bake(const std::string& input, const std::string& output, const std::string& lemmaDict){
	std::ifstream fin(input); // файл с текстом
	std::ifstream finDict("w2v_project.txt");
	Controller controller;
	std::shared_ptr<DataHub> hubObj = controller.AllocateHub();

	Tokenizer t; // токенизация текста
	controller.SetOperation(&t, hubObj);
	controller.ConstructHub(fin);

	Traincontroller ac(lemmaDict); // заполняем префиксное дерево
	ac.run();
	// приведение слов к нормальной форме
	Lemmatizator l(ac.wordnetObj); // через конструктор передаем объект дерева
	controller.SetOperation(&l, hubObj);
	controller.ConstructHub();

	hubObj->ShowContent();

	DictHandler d;
	controller.SetOperation(&d, hubObj);
	controller.ConstructHub(finDict);

	// DataSetCreator creator(hubObj);
	// std::cout << "!!!!" << "\n";
	DataSetCreator creator;
	// std::cout << "!!!!" << "\n";
	creator.createDataSet(output, hubObj->sentences, hubObj->sents_embeddings);
	// std::cout << "@@@" << "\n";
}