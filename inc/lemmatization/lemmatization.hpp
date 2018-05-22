#ifndef lemmatization_hpp
#define lemmatization_hpp

#include "DataHubBuilder.hpp"
#include "dataStructs.hpp"
#include "traincontroller.hpp"
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <boost/tokenizer.hpp>
#include <experimental/optional>

class Lemmatizator : public DataHubBuilder
{
public:
	Lemmatizator(const std::shared_ptr<WordNet>& ptr) : wordnetObj(ptr) {}
	void fillHub();
	void tokensToLemma(); // приведение слов к нормальной форме

private:
	void BuildLemmaTokens(const std::vector<std::vector<std::experimental::optional<std::string>>>& lt) { hub->SetLemmaTokens(lt); }
	std::shared_ptr<WordNet> wordnetObj;
};



#endif /* lemmatization_hpp */