#include "DataHub.hpp"


void DataHub::ReadText(std::ifstream& input)
{
	std::string line;
	while (getline(input, line))
	{
		text = text + line;
	}
}


void DataHub::ReadDict(std::ifstream& file, std::string delimiter, std::string delimiter_vec)
{
	// TODO throw feof
    // if (file.eof() || !file.is_open())
    //     return 0;
    
    std::string s; // содержит строку файла
    
    while (std::getline(file, s)) // получение единой строки из текста
    {
        
        unsigned long id = 0;
        std::string word;
        std::vector<double> vec;
        
        int i = 0;
        size_t pos = 0;
        std::string token;
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            if (i == 0)
                id = atoi(token.c_str());
            else if (i == 1)
                word = token;
            
            s.erase(0, pos + delimiter.length());
            i++;
        }
        while ((pos = s.find(delimiter_vec)) != std::string::npos) {
            token = s.substr(0, pos);
            vec.push_back(atof(token.c_str()));
            s.erase(0, pos + delimiter_vec.length());
        }
        vec.push_back(atof(s.c_str()));
        
        dictelem_t elem(id, word, vec);
        dict.push_back(elem);
    }
};


std::string DataHub::getText()
{
	return text;
}

std::vector<dictelem_t> DataHub::getDict()
{
	return dict;
}
