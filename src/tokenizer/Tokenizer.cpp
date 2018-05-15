#include "Tokenizer.hpp"
#include "traincontroller.hpp"
#include "traindataparser.hpp"
#include <iostream>


void Tokenizer::parseToSentenses(){ // разделение на предложения
	boost::char_separator<char> sep("!?."); // разделители
	boost::tokenizer<boost::char_separator<char>> tokens(text, sep);
	for (auto it : tokens){
		sentences.push_back(it);
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
	for (auto sentence : normalized_sent){ // идем по векторы нормализованных предложений
		boost::tokenizer<boost::char_separator<char>> words(sentence, sep);
		for (auto it : words){
			sep_sentence.push_back(it);
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
	for (auto sentence : tokens){ // цикл по предложеням в массиве
		for (auto word : sentence){ // цикл по словам в предложении
			lemma_sentences.push_back(ac.wordnetObj->find_lemma_of_word(word).value_or(word));
		}
		lemma_tokens.push_back(lemma_sentences);
		lemma_sentences.clear();
	}
}
/*
Нормализация - очищение предложений от знаков
*/


std::vector<std::string> Tokenizer::normalize(std::vector<std::string>& array_of_sentences){ 
	std::string signes ("()-<>/[]{}|*");
	for (auto sentence: array_of_sentences){
		for (int j = 0; j < sentence.size(); ++j){
			if (signes.find(sentence[j]) != std::string::npos){
				sentence.erase(sentence.begin()+j);
			}
		}
	}
	return array_of_sentences;	
}

