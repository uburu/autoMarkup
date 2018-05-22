#ifndef dict_handler_hpp
#define dict_handler_hpp


#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "model.hpp"
#include "types.hpp"
#include "DataHubBuilder.hpp"
#include "dataStructs.hpp"


class DictHandler: public DataHubBuilder
{
	Model <std::string, dictelem_t> wordModel; // хеш таблица, где ключ - слово
	Model <size_t, dictelem_t> idModel; // хеш таблица, где ключ - id слова
public:
	DictHandler() {};
	~DictHandler() {};

	void readFile(std::ifstream& input);

	void fillModels(); 
    void fillModels(std::string delimiter, std::string delimiter_vec); 
	
    
    unsigned long getId(const std::string key);
    std::vector<double> getVector(const size_t req_id);
    std::vector<double> getVector(const std::string key);
    
    void Word2Vector();
 //    void Word2Id(class DataHub& datahub); /// Поиск id слов и их замена
 //    void Id2Vector(class DataHub& datahub); /// Поиск веторного представления слов по id
    
 //    void fitModel(class DataHub& datahub);  
    // void fit(std::ifstream& file, std::string delimiter, std::string delimiter_vec);

    void BuildDict(const std::vector<dictelem_t>& d) { hub->SetDict(d); }
    void BuildSentsId(const std::vector<word2id_t>& si){ hub->SetSentsId(si); } 
    void BuildSentsEmbeddings(const std::vector<id2vector_t>& se) { hub->SetSentsEmbeddings(se); } 


	void fillHub();
	
	std::string delimiter = " ";
	std::string delimiter_vec = ",";
};


#endif /* dicthandler_hpp */
