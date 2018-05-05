#include <iostream>
#include "wordnet.hpp"
#include "traincontroller.hpp"
#include "traindataparser.hpp"

Traincontroller::Traincontroller()
{}

bool Traincontroller::run(){
	if (!readFile("../../autoMarkup/lemmatization/Lemmadict.txt")){
		return false;
	}

	TrainDataParser* parser = new TrainDataParser;
	if (!parser->parse(fileData)){
		delete parser;
		return false;
	}

	wordnetObj = parser->wordNet(); // TODO сделать в классе train метод возвращающий объект
	delete parser;
	return true;
}

std::shared_ptr<WordNet> Traincontroller::getcontroller(){ // возвращает объект готового дерева
	return wordnetObj;
}

bool Traincontroller::readFile(const std::string& filepath){
	Filemanager *curfile = new Filemanager;

	if (!curfile->read(filepath)){
		delete curfile;
		return false;
	}

	fileData = curfile->getdata();
	delete curfile;
	return true;
}