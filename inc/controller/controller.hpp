#ifndef controller_hpp
#define controller_hpp

#include "DataHub.hpp"
#include "DataHubBuilder.hpp"

class Controller
{
public:
	std::shared_ptr<DataHub> AllocateHub();
	void SetOperation(std::shared_ptr<DataHubBuilder> h, std::shared_ptr<DataHub> &emptyHub);
	std::shared_ptr<DataHub> GetHub();

	void ConstructHub(std::ifstream& input); // метод заполнения DataHub c прочтением файла 
	void ConstructHub(); // просто метод 
private:
	std::shared_ptr<DataHubBuilder> hubBuilder;
};

#endif /* contoller_hpp*/