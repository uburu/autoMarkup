#ifndef model_hpp
#define model_hpp


#include <iterator>
#include <unordered_map>

#include <iostream>

#include "hashTable.hpp"


/// Заместитель для хеш-таблицы
template<typename Key, typename Value>
class IModel 
{
public:

	virtual Value get(const Key key);
	virtual bool exist(const Key key);
	virtual void add(const Key key, const Value value);
	virtual void del(const Key key);
};


template<typename Key, typename Value>
class ModelProxy : public IModel 
{
public:
    ModelProxy()
    {
        model = new HashTable<Key, Value>();
    }
    virtual ~ModelProxy()
    {
        delete model;
    }
    virtual Value get(const Key key) 
    {
        return model->get(key);
    }
    
    virtual bool exist(const Key key) 
    {
        return model->exist(key);
    }
    
    virtual void add(const Key key, const Value value) 
    {
        model->add(key, value);
    }
    
    virtual void del(const Key key) 
    {
        model->div(key);
    }
    
private:
	std::shared_ptr<IModel> model;
};



#endif /* model_hpp */
