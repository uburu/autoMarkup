#include <iostream>
#include "wordnet.hpp"
#include "traincontroller.hpp"
#include "traindataparser.hpp"

bool Traincontroller::run(){
	if (!readFile()){ // файл нужно указывать относительно места откуда вызывается метод run
		return false;
	}

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

bool Traincontroller::readFile(){
	std::shared_ptr<Filemanager> curfile(new Filemanager);

	if (!curfile->read(filePath)){ // чтение словаря
		return false;
	}

	// fileData - приватный член, хранящий строки словаря на уровне класса Traindata
	fileData = curfile->getdata(); // получение строк словаря из класса Filemanager на уровень класса Traincontroller
	return true;
}

// mmap 