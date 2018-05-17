#ifndef DataHubBuilder_hpp
#define DataHubBuilder_hpp

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <experimental/optional>
#include "dataStructs.hpp"
#include "DataHub.hpp"


class DataHubBuilder
{
public:	
	std::shared_ptr<DataHub> hub;
	std::shared_ptr<DataHub> GetHub();
	void createNewModule();
	void readFile(std::ifstream& input);

	virtual void fillHub(){};
};

#endif /* DataHubBuilder_hpp*/