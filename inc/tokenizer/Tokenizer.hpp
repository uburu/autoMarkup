#ifndef Tokenizer_hpp
#define Tokenizer_hpp

#include "DataHub.hpp"
#include "dataStructs.hpp"
#include "traincontroller.hpp"
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <boost/tokenizer.hpp>
#include <experimental/optional>


class Tokenizer : public DataHub
{

public:
	Tokenizer() {}; // конструктор
	~Tokenizer() {}; // деструктор

	void parseToSentenses(); // разделение на предлажения
	void parseSentencesToWords(); // разделение предложений на слова
	void tokensToLemma(); // приведение слов к нормальной форме
private:
	std::shared_ptr<WordNet> wordnetObj;
	std::vector<std::string> normalize(std::vector<std::string>& array);	
};


#endif /* Tokenizer_hpp */
