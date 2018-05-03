#include "filemanager.hpp"
// #include "utf8.hpp"

// Filemanager::Filemanager() : data(std::make_shared<Utf16LineList>())
// {}

Filemanager::Filemanager() : data(std::make_shared<std::vector<std::string>>())
{}

bool Filemanager::read(const std::string& filepath){
	file.open(filepath);

	if (!file.is_open())
		return false;

	if (!readData()){
		file.close();
		return false;
	}

	file.close();
	return true;
}

Filemanager::Data Filemanager::getdata(){
	return data;
}

bool Filemanager::readData(){
	std::string line;

	while (std::getline(file, line)){
		data->push_back(line);
	}
	return true;
}


// bool Filemanager::readData()
// {
// 	std::string line;
// 	unsigned lineIndex = 1;

// 	data->clear();

// 	// Read file content
// 	while (std::getline(file, line)) {
// 		// Check for invalid UTF-8
// 		std::string::iterator end_it = utf8::find_invalid(line.begin(), line.end());
// 		if (end_it != line.end()) {
// 			return false;
// 		}

// 		// Convert it to UTF-16
// 		Utf16Line utf16line;
// 		utf8::utf8to16(line.begin(), end_it, std::back_inserter(utf16line));

// 		// Skip BOM (Byte Order Mark) bytes
// 		if (lineIndex == 1) {
// 			bool hasBom = utf8::starts_with_bom(line.begin(), line.end());
// 			if (hasBom)
// 				utf16line.erase(0, 1);
// 		}

// 		// Append to data
// 		data->push_back(utf16line);

// 		++lineIndex;
// 	}

// 	return true;
// }
