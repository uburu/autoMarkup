#include "controller.hpp"

void Controller::SetOperation(DataHubBuilder* h){
	hubBuilder = h;
}

std::shared_ptr<DataHub> Controller::GetHub(){
	return hubBuilder->GetHub();
}

void Controller::ConstructHub(std::ifstream& input){
	hubBuilder->createNewModule();
	hubBuilder->readFile(input);
	hubBuilder->fillHub();
}