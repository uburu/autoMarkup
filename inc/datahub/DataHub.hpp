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
    // void SetLemmaTokens(const std::vector<std::vector<std::experimental::optional<std::string>>>& lt);

    void ShowContent();

    void SetDict(const std::vector<dictelem_t>& d);
    void SetSentsId(const std::vector<word2id_t>& si);
    void SetSentsEmbeddings(const std::vector<id2vector_t>& se);

    /*
    Структуры Tokenizer 
    */

    std::string text; /// текст для токенизации
    std::vector<std::string> sentences; /// массив предложений из текста
    std::vector<token_t> tokens; /// массив слов (токенов)
    // std::vector<std::vector<std::experimental::optional<std::string>>> lemma_tokens; // лемманизированный массив слов

    /*
    Структуры Dicthandler (Никита)
    */

    std::vector<dictelem_t> dict; /// словарь w2v
    std::vector<word2id_t> sents_id; /// id слов в предложениях
    std::vector<id2vector_t> sents_embeddings; /// векторные представления слов в предложениях

};

#endif /* DataHub_hpp */