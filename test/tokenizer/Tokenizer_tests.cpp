#include "baker.hpp"

int main()
{
	std::string textPath = "test_text.txt";
	Baker cookieSet;
	cookieSet.bake(textPath);
	return 0;
}
