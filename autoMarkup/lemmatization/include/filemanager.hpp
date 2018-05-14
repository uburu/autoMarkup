#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <fstream>
#include <string>
#include <vector>
#include <memory>

class Filemanager
{
public:
	// typedef std::string Utf16Line;
	// typedef std::vector<Utf16Line> Utf16LineList;
	// typedef std::shared_ptr<Utf16LineList> Data; // shared ptr to vector of UTF-16 lines

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