#ifndef Tokenizer_hpp
#define Tokenizer_hpp

#include "DataHubBuilder.hpp"
#include "dataStructs.hpp"
#include "traincontroller.hpp"
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <boost/tokenizer.hpp>
#include <experimental/optional>


class Tokenizer : public DataHubBuilder
{
public:

	void readFile(std::ifstream& input);
	void fillHub(); // заполнение DataHub, такой метод должен быть у любого класса заполняющего DataHub

	void parseToSentenses(); // разделение на предлажения
	void parseSentencesToWords(); // разделение предложений на слова
	// void tokensToLemma(); // приведение слов к нормальной форме

private:
	void BuildText(const std::string& tx) { hub->SetText(tx); }
    void BuildSentences(const std::vector<std::string>& s) { hub->SetSentences(s); }
    void BuildTokens(const std::vector<token_t>& t) { hub->SetTokens(t); } 
    // void BuildLemmaTokens(const std::vector<std::vector<std::experimental::optional<std::string>>>& lt) { hub->SetLemmaTokens(lt); }
	
	// std::shared_ptr<WordNet> wordnetObj;
	std::vector<std::string> normalize(std::vector<std::string>& array);	
};


#endif /* Tokenizer_hpp */
