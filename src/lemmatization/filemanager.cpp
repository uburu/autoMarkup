#include "filemanager.hpp"

Filemanager::Filemanager() : data(std::make_shared<std::vector<std::string>>())
{}

// открытие файла со словарем
bool Filemanager::read(const std::string& filepath){
	file.open(filepath);

	if (!file.is_open())
		return false;

	if (!readData()){
		file.close();
		return false;
	}

	file.close();
	return true;
}


Filemanager::Data Filemanager::getdata(){
	return data;
}

// прочтение строк словаря в переменную data
bool Filemanager::readData(){
	std::string line;

	while (std::getline(file, line)){
		data->push_back(line);
	}
	return true;
}