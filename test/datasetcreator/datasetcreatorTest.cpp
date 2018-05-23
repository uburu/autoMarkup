#include "baker.hpp"

int main()
{
	std::string textPath = "corpus_part.en_ru.1m.ru";
	std::string dataSetPath = "DataSet.csv";
	Baker cookieSet;
	cookieSet.bake(textPath, dataSetPath, 0.88, 1);
	return 0;
}