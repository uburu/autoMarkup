#ifndef Tokenizer_hpp
#define Tokenizer_hpp

#include "../DataHub/DataHub.hpp"
#include "../dataStructs.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <boost/tokenizer.hpp>

class Tokenizer : public DataHub
{

public:
	Tokenizer() {}; // конструктор
	~Tokenizer() {}; // деструктор

	void sentence_token(); // разделение на предлажения
	void sentence_to_words();
private:
	std::vector<std::string> normalize(std::vector<std::string>& array);
	
};


#endif /* Tokenizer_hpp */
