#ifndef TRAINCONTROLLER_HPP
#define TRAINCONTROLLER_HPP

#include <string>
#include <memory>
#include "wordnet.hpp"
#include "filemanager.hpp"

class Traincontroller
{
public:
	Traincontroller(const std::string& path);
	bool run();
	std::shared_ptr<WordNet> getcontroller();
	std::shared_ptr<WordNet> wordnetObj; // объект, хранящий в себе дерево 
private:
	std::string filePath;
	bool readFile(); // чтение строк словаря в переменную fileData
	Filemanager::Data fileData; // хранит в себе строки словаря
};


#endif // TRAINCONTROLLER_HPP