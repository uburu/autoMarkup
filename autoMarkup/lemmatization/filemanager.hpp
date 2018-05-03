#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <fstream>
#include <string>
#include <vector>
#include <memory>

class Filemanager
{
public:
	typedef std::shared_ptr<std::vector<std::string>> Data; // shared_ptr of vector of string lines
	Filemanager();
	bool read(const std::string& filepath);
	Data getdata();
private:
	bool readData();
	std::ifstream file;
	Data data;
};

#endif // FILEMANAGER_HPP