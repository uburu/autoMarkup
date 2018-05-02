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
	std::string text; /// текст для токенизации
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

    std::string getText();
    std::vector<dictelem_t> getDict();
};

#endif /* DataHub_hpp */