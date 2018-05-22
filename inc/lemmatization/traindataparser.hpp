#ifndef TRAINDATAPARSER_HPP
#define TRAINDATAPARSER_HPP
#include <string>
#include <memory>
#include "wordnet.hpp"
#include "filemanager.hpp"


class TrainDataParser
{
public:
	TrainDataParser() : wordnetObj(std::make_shared<WordNet>()) {}

	bool parse(const Filemanager::Data fileData); // заполнение дерева
	std::shared_ptr<WordNet> wordNet(); // метод для получения объекта дерева 
private:
	std::shared_ptr<WordNet> wordnetObj; // объект - хранящий в себе дерево
};

#endif // TRAINDATAPARSER_H