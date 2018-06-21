#include "baker.hpp"

void Baker::bake(const std::string& input, const std::string& lemmaDict){
	std::ifstream fin(input); // файл с текстом

	Controller controller;
	std::shared_ptr<DataHub> hubObj = controller.AllocateHub();

	std::shared_ptr<DefaultTokenizerCore> tokenCore; // объект реализации токенизации (паттерн abstract factory)
	std::shared_ptr<Tokenizer> t(tokenCore); // токенизация текста, передаем объект, хранящий реализацию токенизации
	controller.SetOperation(t, hubObj);
	controller.ConstructHub(fin);



	Traincontroller ac(lemmaDict); // заполняем префиксное дерево
	ac.run();
	std::shared_ptr<WordNet> net = ac.wordnetObj;
	// приведение слов к нормальной форме
	std::shared_ptr<DefaultLemmatizatorCore> lemmaCore; // объект реализации лемматизации (паттерн abstract factory)
	std::shared_ptr<Lemmatizator> l(net, lemmaCore); // через конструктор передаем объект дерева, и объект, хранящий реализацию лемматизации
	controller.SetOperation(l, hubObj);
	controller.ConstructHub();

	hubObj->ShowContent();
}