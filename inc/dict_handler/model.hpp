#ifndef model_hpp
#define model_hpp


#include <iterator>
#include <unordered_map>

#include <iostream>


/*
* Класс для хранения словаря
*/
template<typename Key, typename Value>
class Model 
{
	std::unordered_map<Key, Value> map;
public:
	Model(){};
	~Model(){};

	Value get(const Key key) { return map.at(key); /* если нет то throw std::out_of_range */ };
	bool exist(const Key key)
	{
		auto search = map.find(key);
		return search != map.end(); // если не найден, то iterator.end()
	};
	void add(const Key key, const Value value) { map.insert(std::make_pair(key, value)); };

	void del(const Key key) { map.erase(key); };

};



#endif /* model_hpp */
