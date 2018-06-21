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


// abstract factory
class LemmaFactory;

class Lemmatizator : public DataHubBuilder
{
public:
	Lemmatizator(){}
	Lemmatizator(const std::shared_ptr<WordNet>& ptr, const std::shared_ptr<LemmaFactory>& f) : wordnetObj(ptr), product(f) {}
	void fillHub();

private:
	std::shared_ptr<LemmaFactory> product;
protected:
	std::shared_ptr<WordNet> wordnetObj;
};


// интерфейс для различных реализаций лемматизации
class LemmaFactory : public Lemmatizator
{
public:
	LemmaFactory(){}
	virtual void tokensToLemma() = 0;

protected: // могут использоваться в классах-наследниках
	void BuildLemmaTokens(const std::vector<std::vector<std::experimental::optional<std::string>>>& lt) { hub->SetLemmaTokens(lt); }

};


// реализация лемматизатора, передается в конструктор классу Lemmatizator
class DefaultLemmatizatorCore : public LemmaFactory
{
public:
	DefaultLemmatizatorCore(){}
	virtual void tokensToLemma();
};





#endif /* lemmatization_hpp */