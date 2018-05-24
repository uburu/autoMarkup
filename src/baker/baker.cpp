#include "baker.hpp"
#include <time.h>

void Baker::bake(const std::string& input, const std::string& output, double threshold, bool verbose, const std::string& lemmaDict){
	std::ifstream fin(input); // файл с текстом
	std::ifstream finDict("w2v_project.txt");
	Controller controller;
	std::shared_ptr<DataHub> hubObj = controller.AllocateHub();

	const time_t timer = time(NULL);

	auto start = ctime(&timer);
	if (verbose) std::cout << "Start tokenization\n";
	Tokenizer t; // токенизация текста
	controller.SetOperation(&t, hubObj);
	controller.ConstructHub(fin);
	auto end = ctime(&timer);
	if (verbose) std::cout << "Done tokenization \n";
	
	// Traincontroller ac(lemmaDict); // заполняем префиксное дерево
	// ac.run();
	// приведение слов к нормальной форме
	// Lemmatizator l(ac.wordnetObj); // через конструктор передаем объект дерева
	// controller.SetOperation(&l, hubObj);
	// controller.ConstructHub();

	// hubObj->ShowContent();
	if (verbose) std::cout << "Start vectorization\n";
	start = ctime(&timer);

	DictHandler d;
	controller.SetOperation(&d, hubObj);
	controller.ConstructHub(finDict);
	end = ctime(&timer);

	if (verbose) std::cout << "Done vectorization \n";

	if (verbose) std::cout << "sents_embeddings size = " << hubObj->sents_embeddings.size() << "\n";


	if (verbose) std::cout << "Start creating dataset\n";
	start = ctime(&timer);

	DataSetCreator creator;

	creator.createDataSet(output, hubObj->sentences, hubObj->sents_embeddings, threshold);
	end = ctime(&timer);

	if (verbose) std::cout << "Done creating dataset \n";
}