#include "baker.hpp"

int main(int argc, char *argv[])
{
	std::string textPath = argv[1];
	std::string lemmaDict = argv[2]; 
	Baker cookieSet;
	cookieSet.bake(textPath, lemmaDict);
	return 0;
}
