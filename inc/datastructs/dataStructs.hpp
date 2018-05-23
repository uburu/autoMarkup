#ifndef dataStructs_hpp
#define dataStructs_hpp


#include <vector>
#include <string>


typedef std::vector<std::string> token_t;


struct dictelem_t
{
    size_t id; /// индекс слова в словаре
    std::string word;
    std::vector<double> vec; /// вектор слова типа double
    dictelem_t(){}
    dictelem_t(const size_t id_val, const std::string word_val, const std::vector<double> vec_val) : id(id_val), word(word_val), vec(vec_val) {}
};


struct word2id_t
{
    size_t sent_id; /// индекс предложения в словаре
    std::vector<size_t> word_id; // вектор id слов в предложении
    word2id_t(){}
    word2id_t(const size_t sent_id_val, const std::vector<size_t> word_id_val) : sent_id(sent_id_val), word_id(word_id_val) {}
};


struct id2vector_t
{
    size_t sent_id; /// индекс предложения в словаре
    std::vector<std::vector<double> > word_embeddings; // вектор векторных представлений слов в предложении
    id2vector_t(){}
    id2vector_t(const size_t sent_id_val, const std::vector<std::vector<double> > word_embeddings_val) : sent_id(sent_id_val), word_embeddings(word_embeddings_val) {}
};


#endif /* dataStructs_hpp */
