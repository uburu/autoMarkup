#ifndef TRAINDATAPARSER_HPP
#define TRAINDATAPARSER_HPP
#include <string>
#include <memory>
#include "wordnet.hpp"
#include "filemanager.hpp"


class TrainDataParser
{
public:
	TrainDataParser();

	bool parse(const Filemanager::Data& fileData);
	std::shared_ptr<WordNet> wordNet();
private:
	std::shared_ptr<WordNet> wordnetObj;
};

#endif // TRAINDATAPARSER_H