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


class Baker
{
public:
	Baker(){}
	virtual void bake(const std::string& input, const std::string& lemmaDict);
};


#endif /* baker_hpp */