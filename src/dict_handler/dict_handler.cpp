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
            {
                char *pEnd;
                long int id = strtol(token, &pEnd);
            }
            else if (i == 1)
                word = token;
            
            s.erase(0, pos + delimiter.length());
            i++;
        }
        while ((pos = s.find(delimiter_vec)) != std::string::npos) {
            token = s.substr(0, pos);
            char *pEnd;
            float coord = strtof(token, &pEnd);
            vec.push_back(coord);
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
	dictelem_t elem;
    bool exist = false;
    exist = idModel.exist(req_id);
    
    elem = idModel.get(req_id);
    return elem.vec;
};


std::vector<double> DictHandler::getVector(const std::string key)
{
	dictelem_t elem;
    bool exist = false;
    exist = wordModel.exist(key);
    
    elem = wordModel.get(key);
    return elem.vec;
};


void DictHandler::fillModels()
{
    for (auto elem : hub->dict)
    {
    	wordModel.add(elem.word, elem);
    	idModel.add(elem.id, elem);
    }
};


void DictHandler::Word2Vector()
{
    auto tokens_tmp = hub->tokens;

    std::vector<id2vector_t> sents_embeddings_;

    for (auto sentence : tokens_tmp)
    {
        id2vector_t tmp;
        tmp.sent_id = i;
        for (auto token : sentence)
        {
            tmp.word_embeddings.push_back(getVector(token));
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
