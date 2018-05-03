#include "DictHandler.hpp"
#include "../DataHub/DataHubErrors.hpp"


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


void DictHandler::fillModel(class DataHub datahub)
{
    std::vector<dictelem_t> tmp_dict = datahub.getDict();
    for (size_t i = 0; i < tmp_dict.size(); i++)
    {
        model.set(tmp_dict[i].word, tmp_dict[i]);
        model_vec.set(tmp_dict[i].id, tmp_dict[i]);
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


void DictHandler::Word2Id(class DataHub& datahub)
{
    auto tokens_tmp = datahub.getTokens();
    auto sents_id_tmp = datahub.getSents_id();

    for (size_t i = 0; i < tokens_tmp.size(); i++) // итерация по предложениям
    {
        word2id_t tmp;
        tmp.sent_id = i;
        for (size_t w = 0; w < tokens_tmp[i].size(); w++) // итерация по словам предложений
        {
            size_t key = getId(tokens_tmp[i][w]);
            tmp.word_id.push_back(key);
        }
        datahub.addSents_id(tmp);
    }
}


void DictHandler::Id2Vector(class DataHub& datahub)
{
    
    auto sents_id_tmp = datahub.getSents_id();
    for (size_t i = 0; i < sents_id_tmp.size(); i++) // итерация по предложениям
    {
        id2vector_t tmp;
        tmp.sent_id = i;
        for (size_t w = 0; w < sents_id_tmp[i].word_id.size(); w++) // итерация по словам предложений
        {
            std::vector<double> vec = getVector(sents_id_tmp[i].word_id[w]);
            tmp.word_embeddings.push_back(vec);
        }
        datahub.addSents_embeddings(tmp);
    }
}


void DictHandler::fitModel(class DataHub& datahub)
{
    fillModel(datahub);
    Word2Id(datahub);
    Id2Vector(datahub);
};
