#include "Tokenizer.hpp"
#include "traincontroller.hpp"
#include "traindataparser.hpp"
#include <iostream>


void Tokenizer::parseToSentenses(){ // разделение на предложения
	std::vector<std::string> containerSentence;
	boost::char_separator<char> sep("!?."); // разделители
	boost::tokenizer<boost::char_separator<char>> tokens(hub->text, sep);
	for (auto it : tokens){
		containerSentence.push_back(it);
	}
	containerSentence[0];
	BuildSentences(containerSentence); 
}


void Tokenizer::parseSentencesToWords(){ // разделение предложений на слова
	std::vector<token_t> containerTokens;
	std::vector<std::string> sep_sentence;
	std::vector<std::string> normalized_sent;
		
	/*
	если до разбиения предложений на слова текст не был разбит на предложения,
	то есть переменная sentences класс DataHub пуста, вызвать функцию разбиения текста на предложения
	*/

	normalized_sent = normalize(hub->sentences); // получаем вектор нормализированных предложений (создаем нормализированную копию sentenes)

	boost::char_separator<char> sep(" ");
	for (auto sentence : normalized_sent){ // идем по векторы нормализованных предложений
		boost::tokenizer<boost::char_separator<char>> words(sentence, sep);
		for (auto it : words){
			sep_sentence.push_back(it);
		}
		containerTokens.push_back(sep_sentence);
	}
	BuildTokens(containerTokens);
}


void Tokenizer::tokensToLemma(){
	std::vector<std::vector<std::experimental::optional<std::string>>> containerLemmaTokens;

	Traincontroller ac;
	ac.run();

	std::vector<std::experimental::optional<std::string>> lemma_sentences;
	for (auto sentence : hub->tokens){ // цикл по предложеням в массиве
		for (auto word : sentence){ // цикл по словам в предложении
			lemma_sentences.push_back(ac.wordnetObj->find_lemma_of_word(word).value_or(word));
		}
		containerLemmaTokens.push_back(lemma_sentences);
		lemma_sentences.clear();
	}
	BuildLemmaTokens(containerLemmaTokens);
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

void Tokenizer::fillHub(){
	parseToSentenses();
	parseSentencesToWords();
	tokensToLemma();
}