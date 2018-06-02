#ifndef DataHub_hpp
#define DataHub_hpp

#include <iostream>
#include <vector>
#include <string>
#include "dataStructs.hpp"




class DataHub
{
public:
    DataHub(){}
    ~DataHub(){}


    void SetDict(const std::vector<dictelem_t>& d);
    void SetSentsId(const std::vector<word2id_t>& si);
    void SetSentsEmbeddings(const std::vector<id2vector_t>& se);

    /*
    Структуры Dicthandler (Никита)
    */
    
    std::vector<dictelem_t> dict; /// словарь w2v
    std::vector<word2id_t> sents_id; /// id слов в предложениях
    std::vector<id2vector_t> sents_embeddings; /// векторные представления слов в предложениях

    
};

#endif /* DataHub_hpp */