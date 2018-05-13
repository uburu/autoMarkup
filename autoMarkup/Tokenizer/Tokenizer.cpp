#include "Tokenizer.hpp"
#include "../lemmatization/traincontroller.hpp"
#include "../lemmatization/traindataparser.hpp"
#include <iostream>


void Tokenizer::parseToSentenses(){ // разделение на предложения
	boost::char_separator<char> sep("!?."); // разделители
	boost::tokenizer<boost::char_separator<char>> tokens(text, sep);
	for (auto it : tokens){
		sentences.push_back(it);
		std::cout << it << "\n";
	}
}


void Tokenizer::parseSentencesToWords(){ // разделение предложений на слова
	std::vector<std::string> sep_sentence;
	std::vector<std::string> normalized_sent;
		
	/*
	если до разбиения предложений на слова текст не был разбит на предложения,
	то есть переменная sentences класс DataHub пуста, вызвать функцию разбиения текста на предложения
	*/
	if (sentences.size() == 0) 
		parseToSentenses();
	
	normalized_sent = normalize(sentences); // получаем вектор нормализированных предложений (создаем нормализированную копию sentenes)

	boost::char_separator<char> sep(" ");
	for (int i = 0; i < normalized_sent.size(); ++i){ // идем по векторы нормализованных предложений
		boost::tokenizer<boost::char_separator<char>> words(normalized_sent[i], sep);
		for (auto it : words){
			sep_sentence.push_back(it);
			std::cout << it << "\n";
		}
		tokens.push_back(sep_sentence);
	}
}


void Tokenizer::tokensToLemma(){
/*
3 способа создать дерево
*/

	// 1 - запустить метод run внутри метода tokens_to_lemma (работает)

	Traincontroller ac;
	ac.run();

	// 2 - запустить метод run() в Tokenizer_test.cpp и взять дерево из класса Traincontroller (будет segmentation fault)
	
	// Traincontroller* obj = new Traincontroller; 
	// wordnetObj = obj->getcontroller();

	// 3 - запустить метод run() в Tokenizer_test.cpp и взять дерево из класса TraindataParser (дерево не заполнится но не будет segmentation fault)
	// метод find_lemma_of_word всегда возвращает nullptr
	
	// TrainDataParser* obj = new TrainDataParser;
	// wordnetObj = obj->wordNet();


	std::vector<std::experimental::optional<std::string>> lemma_sentences;
	for (int i = 0; i < tokens.size(); i++){ // цикл по предложеням в массиве
		for (int j = 0; j < tokens[i].size(); j++){ // цикл по словам в предложении
			lemma_sentences.push_back(ac.wordnetObj->find_lemma_of_word(tokens[i][j]).value_or(tokens[i][j]));
		}
		lemma_tokens.push_back(lemma_sentences);
		lemma_sentences.clear();
	}
	for (int i = 0; i < lemma_tokens.size(); i++){
		for(int j = 0; j < lemma_tokens[i].size(); j++){
			std::cout << lemma_tokens[i][j].value() << " ";
		}
		std::cout << "\n";
	}
}
/*
Нормализация - очищение предложений от знаков
*/
std::vector<std::string> Tokenizer::normalize(std::vector<std::string>& array){ 
	std::string signes ("()-<>/[]{}|*");
	for (int i = 0; i < array.size(); ++i){
		for (int j = 0; j < array[i].size(); ++j){
			if (signes.find(array[i][j]) != std::string::npos){
				array[i].erase(array[i].begin()+j);
			}
		}
	}
	return array;	
}

