#ifndef TRAINCONTROLLER_HPP
#define TRAINCONTROLLER_HPP

#include <string>
#include <memory>
#include "wordnet.hpp"
#include "filemanager.hpp"

class Traincontroller
{
public:
	Traincontroller();
	bool run();
private:
	bool readFile(const std::string& filapath);
	Filemanager::Data fileData;
	std::shared_ptr<WordNet> wordnetObj;
};


#endif // TRAINCONTROLLER_HPP