#include "Tokenizer.hpp"
#include "traincontroller.hpp"
#include "traindataparser.hpp"
#include <iostream>


void DefaultTokenizerCore::parseToSentenses(){ // разделение на предложения
	std::vector<std::string> containerSentence;
	boost::char_separator<char> sep("!?."); // разделители
	boost::tokenizer<boost::char_separator<char>> tokens(hub->text, sep);
	for (auto it : tokens){
		containerSentence.push_back(it);
	}
	BuildSentences(containerSentence); 
}


void DefaultTokenizerCore::parseSentencesToWords(){ // разделение предложений на слова
	std::vector<token_t> containerTokens;
	std::vector<std::string> sep_sentence;
	std::vector<std::string> normalized_sent;
		
	/*
	если до разбиения предложений на слова текст не был разбит на предложения,
	то есть переменная sentences класс DataHub пуста, вызвать функцию разбиения текста на предложения
	*/

	normalized_sent = normalize(hub->sentences); // получаем вектор нормализированных предложений (создаем нормализированную копию sentenes)

	boost::char_separator<char> sep(" ,<>(){}[]'';:«»|#");
	for (auto sentence : normalized_sent){ // идем по векторы нормализованных предложений
		boost::tokenizer<boost::char_separator<char>> words(sentence, sep);
		for (auto it : words){
			sep_sentence.push_back(it);
		}
		containerTokens.push_back(sep_sentence);
		sep_sentence.clear();
	}
	BuildTokens(containerTokens);
}

/*
Нормализация - очищение предложений от знаков
*/


std::vector<std::string> DefaultTokenizerCore::normalize(std::vector<std::string>& array_of_sentences){ 
	std::string signes (",()-<>/[]{}|*");
	for (auto sentence: array_of_sentences){
		for (int j = 0; j < sentence.size(); ++j){
			if (signes.find(sentence[j]) != std::string::npos){
				sentence.erase(sentence.begin()+j);
			}
		}
	}
	return array_of_sentences;	
}




void Tokenizer::readFile(std::ifstream& input){
	std::string containerText;
	std::string line;
	while (getline(input, line)){
		containerText = containerText + line;
	}
	BuildText(containerText);
}

void Tokenizer::fillHub(){
	product->parseToSentenses();
	product->parseSentencesToWords();
}