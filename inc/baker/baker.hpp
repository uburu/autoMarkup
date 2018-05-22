#ifndef baker_hpp
#define baker_hpp

#include <string>
#include <iostream>
#include <fstream>
#include "DataHub.hpp"
#include "DataHubBuilder.hpp"
#include "Tokenizer.hpp"
#include "lemmatization.hpp"
#include "traincontroller.hpp"
#include "controller.hpp"
#include "datasetcreator.hpp"
#include "dict_handler.hpp"


class Baker
{
public:
	Baker(){}
	virtual void bake(const std::string& input, const std::string& output, const std::string& lemmaDict = "../../data/Lemmadict.txt");
};


#endif /* baker_hpp */