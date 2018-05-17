#include "DataHubBuilder.hpp"

void DataHubBuilder::readFile(std::ifstream& input){
	std::string containerText;
	std::string line;
	while (getline(input, line)){
		containerText = containerText + line;
	}
	hub->SetText(containerText);
}

std::shared_ptr<DataHub> DataHubBuilder::GetHub() {
	return hub;
}

void DataHubBuilder::createNewModule(){
	hub.reset(new DataHub);
}