#ifndef controller_hpp
#define controller_hpp

#include "DataHub.hpp"
#include "DataHubBuilder.hpp"

class Controller
{
public:
	DataHubBuilder* hubBuilder;
	std::shared_ptr<DataHub> AllocateHub();
	void SetOperation(DataHubBuilder* h, std::shared_ptr<DataHub> &emptyHub);
	std::shared_ptr<DataHub> GetHub();

	void ConstructHub(std::ifstream& input); // метод заполнения DataHub c прочтением файла 
	void ConstructHub(); // просто метод заполнения
};

#endif /* contoller_hpp*/