#ifndef DictHandler_hpp
#define DictHandler_hpp

#include <iostream>
#include <fstream>
#include "../dataStructs.hpp"
#include "../DataHub/DataHub.hpp"
// #include "Model.hpp"


// TODO move Model to Model.hpp
template<class K, class V, class HashGenerator = myHash<K> >
class Model {
public:
    int size = 8;
    std::vector<std::vector<Bucket<K, V> > > table;
    Model() {
        for(int i = 0; i < size; i++) {
            std::vector<Bucket<K, V> > v;
            table.push_back(v);
        }
    }
    ~Model() {}
    void set(const K &k, const V &v) {
        Bucket<K, V> b(k, v);
        for(int i = 0; i < table[hash(k)].size(); i++)
            if(table[hash(k)][i].key == k) {
                table[hash(k)][i] = b;
                return;
            }
        table[hash(k)].push_back(b);
    }
    V get(const K &k) {
        int i = 0;
        for(; i < table[hash(k)].size(); i++)
            if(table[hash(k)][i].key == k)
                break;
        
        return table[hash(k)][i].val;
        
    }
    bool exist(const K &k) {
        for(int i = 0; i < table[hash(k)].size(); i++)
            if(table[hash(k)][i].key == k)
                return true;
        return false;
    }
    size_t hash(const K &k) {
        return HashGenerator::hashFunction(k) % table.size();
    }
};


class DictHandler: public DataHub
{
    Model<std::string, dictelem_t> model;
    Model<size_t, dictelem_t> model_vec;
public:
    DictHandler(){} //: Model<K, V, HashGenerator>(){}
    ~DictHandler(){}
    
    void fillDict(); //const std::vector<dictelem_t> dict
    void fillDict(std::ifstream& file, std::string delimiter, std::string delimiter_vec); 
    unsigned long getId(const std::string key);
    std::vector<double> getVector(const size_t req_id);
    
    void Word2Id(); /// Поиск id слов и их замена
    void Id2Vector(); /// Поиск веторного представления слов по id
    
    void fit(); /// 
    void fit(std::ifstream& file, std::string delimiter, std::string delimiter_vec);
    
    
    bool dropNF;
};

#endif /* DictHandler_hpp */

