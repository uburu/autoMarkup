#ifndef controller_hpp
#define controller_hpp

#include "DataHub.hpp"
#include "DataHubBuilder.hpp"

class Controller
{
public:
	DataHubBuilder* hubBuilder;
	void SetOperation(DataHubBuilder* h);
	std::shared_ptr<DataHub> GetHub();
	void ConstructHub(std::ifstream& input);
};

#endif /* contoller_hpp*/