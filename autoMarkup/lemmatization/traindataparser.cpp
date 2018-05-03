#include <iostream>
#include <algorithm>
#include "traindataparser.hpp"
#include "wordnet.hpp"

TrainDataParser::TrainDataParser() : wordnetObj(std::make_shared<WordNet>())
{}

bool TrainDataParser::parse(const Filemanager::Data& fileData){
	const char delimeter = ',';
	for (auto line : *fileData){
		if (line.empty())
			continue;

		std::string::iterator delimIt = std::find(line.begin(), line.end(), delimeter);
		if (delimIt == line.end())
			continue;

		std::string word(line.begin(), delimIt);
		std::string lemma(delimIt+1, line.end());

		bool badLine = std::find(lemma.begin(), lemma.end(), delimeter) != lemma.end();
		if (word.empty() || lemma.empty() || badLine)
			continue;

		wordnetObj->insert(word,lemma);
	}
	return true;

}

std::shared_ptr<WordNet> TrainDataParser::wordNet(){
	return wordnetObj;
}