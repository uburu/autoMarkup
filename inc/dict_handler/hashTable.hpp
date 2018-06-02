#ifndef hashTable_hpp
#define hashTable_hpp


#include <iterator>
#include <unordered_map>

#include <iostream>

#include "model.hpp"


/*
* Класс для хранения словаря
*/
template<typename Key, typename Value>
class HashTable : public IModel
{
	std::unordered_map<Key, Value> map;
public:
	Model(){};
	virtual ~Model(){};

	virtual Value get(const Key key) { return map.at(key); /* если нет то throw std::out_of_range */ };
	virtual bool exist(const Key key)
	{
		auto search = map.find(key);
		return search != map.end(); // если не найден, то iterator.end()
	};
	virtual void add(const Key key, const Value value) { map.insert(std::make_pair(key, value)); };

	virtual void del(const Key key) { map.erase(key); };

};



#endif /* hashTable_hpp */
