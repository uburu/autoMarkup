#include "lemmatization.hpp"

void Lemmatizator::tokensToLemma(){
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


void Lemmatizator::fillHub(){
	tokensToLemma();
}