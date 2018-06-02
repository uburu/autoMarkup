#include "DataHubBuilder.hpp"


std::shared_ptr<DataHub> DataHubBuilder::GetHub() {
	return hub;
}

void DataHubBuilder::createNewModule(){
	hub = new DataHub();
}