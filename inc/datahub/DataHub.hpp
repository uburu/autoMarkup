#ifndef DataHub_hpp
#define DataHub_hpp

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <experimental/optional>
#include "dataStructs.hpp"




class DataHub
{
public:
    DataHub(){}
    ~DataHub(){}

    void SetText(const std::string& tx);
    void SetSentences(const std::vector<std::string>& s);
    void SetTokens(const std::vector<token_t>& t);
    void SetLemmaTokens(const std::vector<std::vector<std::experimental::optional<std::string>>>& lt);

    void ShowContent();
    /*
    text, senteces, tokens формируются в ходе работы класса Tokenizer
    */

    std::string text; /// текст для токенизации
    std::vector<std::string> sentences; /// массив предложений из текста
    std::vector<token_t> tokens; /// массив слов (токенов)
    std::vector<std::vector<std::experimental::optional<std::string>>> lemma_tokens; // лемманизированный массив слов
};

#endif /* DataHub_hpp */