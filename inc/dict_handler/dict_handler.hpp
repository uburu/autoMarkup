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
	std::shared_ptr< IModel <std::string, dictelem_t> > wordModel = new ModelProxy();// хеш таблица, где ключ - слово
	std::shared_ptr< IModel <size_t, dictelem_t> > idModel = new ModelProxy();// хеш таблица, где ключ - id слова
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

    void BuildDict(const std::vector<dictelem_t>& d) { hub->SetDict(d); }
    void BuildSentsId(const std::vector<word2id_t>& si){ hub->SetSentsId(si); } 
    void BuildSentsEmbeddings(const std::vector<id2vector_t>& se) { hub->SetSentsEmbeddings(se); } 


	void fillHub();
	
	std::string delimiter = " ";
	std::string delimiter_vec = ",";
};


#endif /* dicthandler_hpp */
