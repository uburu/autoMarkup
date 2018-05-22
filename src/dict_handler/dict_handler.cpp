#include "dict_handler.hpp"


void DictHandler::readFile(std::ifstream& input)
{

	std::vector<dictelem_t> dict;
    
    std::string s; // содержит строку файла
    
    while (std::getline(input, s)) // получение единой строки из текста
    {
        
        unsigned long id = 0;
        std::string word;
        std::vector<double> vec;
        
        int i = 0;
        size_t pos = 0;
        std::string token;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            if (i == 0)
                id = atoi(token.c_str());
            else if (i == 1)
                word = token;
            
            s.erase(0, pos + delimiter.length());
            i++;
        }
        while ((pos = s.find(delimiter_vec)) != std::string::npos) {
            token = s.substr(0, pos);
            vec.push_back(atof(token.c_str()));
            s.erase(0, pos + delimiter_vec.length());
        }
        vec.push_back(atof(s.c_str()));
        
        dictelem_t elem(id, word, vec);
        dict.push_back(elem);
    }
    BuildDict(dict);
};


size_t DictHandler::getId(const std::string key)
{
    dictelem_t elem;
    bool exist = false;
    exist = wordModel.exist(key);
    if (!exist)
        return 0;
    elem = wordModel.get(key);
    return elem.id;
};


std::vector<double> DictHandler::getVector(const size_t req_id)
{
	// REDO get vector from index = id - 1, id > 0 . Need to provide liniar indexes
    dictelem_t elem;
    bool exist = false;
    exist = idModel.exist(req_id);
    if (!exist)
        std::cout << "Required id does not exist!" << std::endl; // TODO throw
    
    elem = idModel.get(req_id);
    return elem.vec;
};


std::vector<double> DictHandler::getVector(const std::string key)
{
	// REDO get vector from index = id - 1, id > 0 . Need to provide liniar indexes
    dictelem_t elem;
    bool exist = false;
    exist = wordModel.exist(key);
    if (!exist)
    {
        std::cout << "Required id does not exist!  " << key << std::endl; // TODO throw
    }
    else
        elem = wordModel.get(key);
    return elem.vec;
};


void DictHandler::fillModels()
{
    for (size_t i = 0; i < hub->dict.size(); i++)
    {
    	wordModel.add(hub->dict[i].word, hub->dict[i]);
    	idModel.add(hub->dict[i].id, hub->dict[i]);
    }
};


void DictHandler::Word2Vector()
{
    auto tokens_tmp = hub->tokens;

    std::vector<id2vector_t> sents_embeddings_;

    for (size_t i = 0; i < tokens_tmp.size(); i++) // итерация по предложениям
    {
        id2vector_t tmp;
        tmp.sent_id = i;
        for (size_t w = 0; w < tokens_tmp[i].size(); w++) // итерация по словам предложений
        {
            std::cout<< tokens_tmp[i][w] << " (" << getVector(tokens_tmp[i][w]).size() << ") ";
            tmp.word_embeddings.push_back(getVector(tokens_tmp[i][w]));
        }
        sents_embeddings_.push_back(tmp);
    }
    BuildSentsEmbeddings(sents_embeddings_);
}


void DictHandler::fillHub()
{
	fillModels();
	Word2Vector();
}
