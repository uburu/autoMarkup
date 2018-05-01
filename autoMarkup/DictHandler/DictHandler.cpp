#include "DictHandler.hpp"


void DictHandler::fillDict()
{
    for (size_t i = 0; i < dict.size(); i++)
    {
        model.set(dict[i].word, dict[i]);
        model_vec.set(dict[i].id, dict[i]);
    }
};


void DictHandler::fillDict(std::ifstream& file, std::string delimiter, std::string delimiter_vec)
{
    ReadDict(file, delimiter, delimiter_vec);
    for (size_t i = 0; i < dict.size(); i++)
    {
        model.set(dict[i].word, dict[i]);
        model_vec.set(dict[i].id, dict[i]);
    }
};


size_t DictHandler::getId(const std::string key)
{
    dictelem_t elem;
    bool exist = false;
    exist = model.exist(key);
    if (!exist)
        return 0;
    elem = model.get(key);
    return elem.id;
};


std::vector<double> DictHandler::getVector(const size_t req_id)
{
	// REDO get vector from index = id - 1, id > 0 . Need to provide liniar indexes
    dictelem_t elem;
    bool exist = false;
    exist = model_vec.exist(req_id);
    if (!exist)
        std::cout << "Required id does not exist!" << std::endl; // TODO throw
    
    elem = model_vec.get(req_id);
    return elem.vec;
};


void DictHandler::Word2Id()
{
    word2id_t tmp;
    for (size_t i = 0; i < tokens.size(); i++) // итерация по предложениям
    {
        tmp.sent_id = i;
        for (size_t w = 0; w < tokens[i].size(); w++) // итерация по словам предложений
        {
            size_t key = getId(tokens[i][w]);
            tmp.word_id.push_back(key);
        }
        sents_id.push_back(tmp);
    }
}


void DictHandler::Id2Vector()
{
    id2vector_t tmp;
    for (size_t i = 0; i < sents_id.size(); i++) // итерация по предложениям
    {
        tmp.sent_id = i;
        for (size_t w = 0; w < sents_id[i].word_id.size(); w++) // итерация по словам предложений
        {
            std::vector<double> vec = getVector(sents_id[i].word_id[w]);
            tmp.word_embeddings.push_back(vec);
        }
        sents_embeddings.push_back(tmp);
    }
}


void DictHandler::fit()
{
    Word2Id();
    Id2Vector();
};


void DictHandler::fit(std::ifstream& file, std::string delimiter, std::string delimiter_vec)
{
    ReadDict(file, delimiter, delimiter_vec);
    Word2Id();
    Id2Vector();
};
