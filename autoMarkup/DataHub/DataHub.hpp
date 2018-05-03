#ifndef DataHub_hpp
#define DataHub_hpp

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "../dataStructs.hpp"


class DataHub
{   
protected:   

    /*
    text, senteces, tokens формируются в ходе работы класса Tokenizer
    */
	std::string text; /// текст для токенизации
    std::vector<std::string> sentences; /// массив предложений из текста
	std::vector<token_t> tokens; /// массив слов (токенов)
    std::vector<dictelem_t> dict; /// словарь w2v
    std::vector<word2id_t> sents_id; /// id слов в предложениях
    std::vector<id2vector_t> sents_embeddings; /// векторные представления слов в предложениях
    
public:
    DataHub() {};
	~DataHub() {};
    void ReadText(std::ifstream&); /// считывает весь текст в строку
    void WriteTokens(std::ofstream&);
    
    void ReadDict(std::ifstream&, std::string, std::string); /// считывает массив структур словаря (id, word, vector)
    void ReadTokens(std::ifstream&); /// считывает массив слов (токенов)
    void WriteIndexes(std::ofstream&);
    void WriteNFWords(std::ofstream&);
    
    void ReadIndexes();
    void WriteMarkups();


    std::string getText() {return text;};
    std::vector<token_t> getTokens() {return tokens;}; 
    std::vector<dictelem_t> getDict() {return dict;};
    std::vector<word2id_t> getSents_id() {return sents_id;}; 
    std::vector<id2vector_t> getSents_embeddings(){return sents_embeddings;};

    void setText(std::string input) {text = input;};
    void setTokens(std::vector<token_t> input) {tokens = input;}; 
    void setDict(std::vector<dictelem_t> input) {dict = input;};
    void setSents_id(std::vector<word2id_t> input) {sents_id = input;}; 
    void setSents_embeddings(std::vector<id2vector_t> input){sents_embeddings = input;};

    void addText(std::string input) {text = text + input;};
    void addTokens(token_t input) {tokens.push_back(input);}; 
    void addDict(dictelem_t input) {dict.push_back(input);};
    void addSents_id(word2id_t input) {sents_id.push_back(input);}; 
    void addSents_embeddings(id2vector_t input){sents_embeddings.push_back(input);};
};

#endif /* DataHub_hpp */
