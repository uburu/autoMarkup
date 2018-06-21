#ifndef Tokenizer_hpp
#define Tokenizer_hpp

#include "DataHubBuilder.hpp"
#include "dataStructs.hpp"
#include "traincontroller.hpp"
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <experimental/optional>


// abstract factory
class TokensFactory;

class Tokenizer : public DataHubBuilder
{
public:
	Tokenizer(){}
	Tokenizer(const std::shared_ptr<TokensFactory>& f) { product = f; }
	void readFile(std::ifstream& input);
	void fillHub(); // заполнение DataHub, такой метод должен быть у любого класса заполняющего DataHub
private:

	std::shared_ptr<TokensFactory> product;

};



// интерфейс для различных реализаций токенайзера
class TokensFactory : public Tokenizer
{
public:
	TokensFactory(){}
	virtual void parseToSentenses() = 0; // разделение на предлажения
	virtual void parseSentencesToWords() = 0; // разделение предложений на слова

protected: // могут использоваться в классах-наследниках
	void BuildText(const std::string& tx);
    void BuildSentences(const std::vector<std::string>& s);
    void BuildTokens(const std::vector<token_t>& t);

};


// реализация токенайзера. можем написать другой класс с логикой токенизации, который будет реализовывать методы посвоему и
// передать его  в конструктор классу Tokenizer
class DefaultTokenizerCore : public TokensFactory
{
public:
	DefaultTokenizerCore(){}
	virtual void parseToSentenses(); // разделение на предлажения
	virtual void parseSentencesToWords(); // разделение предложений на слова 
private:
	const char *rubbish = " ,<>(){}[]'';:«»|#";
	const char *separators = " ";
	std::vector<std::string> normalize(std::vector<std::string>& array);
};


#endif /* Tokenizer_hpp */
