#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <fstream>
#include <string>
#include <vector>
#include <memory>

class Filemanager
{
public:

	typedef std::shared_ptr<std::vector<std::string>> Data; 
	Filemanager();
	bool read(const std::string& filepath);
	Data getdata();
private:
	bool readData();
	std::ifstream file;
	Data data; // переменная хранящая в себе строки словаря на уровне класса Filemanager
};

#endif // FILEMANAGER_HPP