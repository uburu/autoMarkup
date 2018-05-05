#ifndef Tokenizer_hpp
#define Tokenizer_hpp

#include "../DataHub/DataHub.hpp"
#include "../dataStructs.hpp"
#include "../lemmatization/traincontroller.hpp"
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <boost/tokenizer.hpp>


class Tokenizer : public DataHub
{

public:
	Tokenizer() {}; // конструктор
	~Tokenizer() {}; // деструктор

	void sentence_token(); // разделение на предлажения
	void sentence_to_words(); // разделение предложений на слова
	void tokens_to_lemma(); // приведение слов к нормальной форме
private:
	std::shared_ptr<WordNet> wordnetObj;
	std::vector<std::string> normalize(std::vector<std::string>& array);	
};


#endif /* Tokenizer_hpp */
