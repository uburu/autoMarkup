#include "controller.hpp"

std::shared_ptr<DataHub> Controller::AllocateHub(){
	std::shared_ptr<DataHub> tmpHub(new DataHub);
	return tmpHub; 
}

void Controller::SetOperation(std::shared_ptr<DataHubBuilder> h, std::shared_ptr<DataHub> &emptyHub){
	hubBuilder = h;
	hubBuilder->hub = emptyHub;
}


std::shared_ptr<DataHub> Controller::GetHub(){
	return hubBuilder->GetHub();
}

void Controller::ConstructHub(std::ifstream& input){
	hubBuilder->readFile(input);
	hubBuilder->fillHub();
}


void Controller::ConstructHub(){
	hubBuilder->fillHub();
}
