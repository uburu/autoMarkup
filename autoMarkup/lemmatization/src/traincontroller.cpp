#include <iostream>
#include "wordnet.hpp"
#include "traincontroller.hpp"
#include "traindataparser.hpp"

Traincontroller::Traincontroller()
{}

bool Traincontroller::run(){
	if (!readFile("../../lemmatization/Lemmadict.txt")){ // файл нужно указывать относительно места откуда вызывается метод run
		std::cout << "WRONG PATH" << "\n";
		return false;
	}

	// TrainDataParser* parser = new TrainDataParser;
	std::shared_ptr<TrainDataParser> parser(new TrainDataParser);
	if (!parser->parse(fileData)){ // построение дерева 
		return false;
	}

	wordnetObj = parser->wordNet(); // получение объекта, хранящего дерево, из класса Traindataparser на уровень класса Traincontroller
	return true;
}

std::shared_ptr<WordNet> Traincontroller::getcontroller(){ // возвращает объект готового дерева
	return wordnetObj;
}

bool Traincontroller::readFile(const std::string& filepath){
	std::shared_ptr<Filemanager> curfile(new Filemanager);

	if (!curfile->read(filepath)){ // чтение словаря
		return false;
	}

	// fileData - приватный член, хранящий строки словаря на уровне класса Traindata
	fileData = curfile->getdata(); // получение строк словаря из класса Filemanager на уровень класса Traincontroller
	return true;
}