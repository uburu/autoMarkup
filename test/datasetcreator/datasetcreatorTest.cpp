#include "baker.hpp"

int main()
{
	std::string textPath = "test_text.txt";
	std::string dataSetPath = "DataSet.csv";
	Baker cookieSet;
	cookieSet.bake(textPath, dataSetPath);
	return 0;
}