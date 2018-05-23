#ifndef datasetcreator_hpp
#define datasetcreator_hpp

#include "DataHub.hpp"
#include "DataHubBuilder.hpp"
#include "Tokenizer.hpp"
// #include "lemmatization.hpp"
// #include "traincontroller.hpp"
#include "controller.hpp"
#include "dict_handler.hpp"
#include <iostream>
#include <fstream>
#include <markup/markup_factory.hpp>
#include <memory>
#include <cassert>

class DataSetCreator
{
public:
	DataSetCreator(){};
	// DataSetCreator(const std::shared_ptr<DataHub>& ptr);

	void createDataSet(const std::string& path, std::vector<std::string> sentences, std::vector<id2vector_t> sents_embeddings, double threshold);
// private:
// 	std::shared_ptr<DataHub> hub;

};


#endif /* datasetcreator_hpp */