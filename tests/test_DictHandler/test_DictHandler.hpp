#include <iostream>
#include <assert.h>
#include <boost/test/minimal.hpp>
#include "../../autoMarkup/DataHub/DataHub.hpp"
#include "../../autoMarkup/DictHandler/DictHandler.hpp"

#define PATH "../data/tests/" // path to data


void test_DictHandler_fillDict_1()
{
    std::ifstream file;
    std::string path = PATH;
    path += "dict.txt"; /// file name
    file.open(path); 
    
    DictHandler dict;
    dict.fillDict(file, " ", ",");
    file.close();
    
    BOOST_REQUIRE(dict.getId("привет") == 1);
}


void test_DictHandler_fillDict_2()
{
    std::ifstream file;
    std::string path = PATH;
    path += "dict.txt"; /// file name
    file.open(path); 
    
    DictHandler dict;
    dict.fillDict(file, " ", ",");
    file.close();
    
    BOOST_REQUIRE(dict.getId("нет") == 0);
}


void test_DictHandler_fillDict_3()
{
    DataHub dh;
    std::string path = PATH;
    path += "dict.txt"; /// file name
    std::ifstream file;


    file.open(path);
    dh.ReadDict(file, " ", ",");
    file.close();

    // set an example tokens
    std::vector<token_t> tokens_tmp;
    token_t tmp_words_1, tmp_words_2;
    tmp_words_1.push_back("привет");
    tmp_words_1.push_back("как");
    tmp_words_1.push_back("дела");
    tokens_tmp.push_back(tmp_words_1);
    
    tmp_words_2.push_back("хорошо");
    tmp_words_2.push_back("а");
    tmp_words_2.push_back("у");
    tmp_words_2.push_back("тебя");
    tokens_tmp.push_back(tmp_words_2);


    dh.setTokens(tokens_tmp);

    BOOST_REQUIRE(dh.getTokens().size() == 2);
}


void test_DictHandler_fillDict_4()
{
    DataHub dh;
    std::string path = PATH;
    path += "dict.txt"; /// file name
    std::ifstream file;


    file.open(path);
    dh.ReadDict(file, " ", ",");
    file.close();

    // set an example tokens
    std::vector<token_t> tokens_tmp;
    token_t tmp_words_1, tmp_words_2;
    tmp_words_1.push_back("привет");
    tmp_words_1.push_back("как");
    tmp_words_1.push_back("дела");
    tokens_tmp.push_back(tmp_words_1);
    
    tmp_words_2.push_back("хорошо");
    tmp_words_2.push_back("а");
    tmp_words_2.push_back("у");
    tmp_words_2.push_back("тебя");
    tokens_tmp.push_back(tmp_words_2);

    dh.setTokens(tokens_tmp);

    DictHandler dict_table;
    dict_table.fitModel(dh);
    

    BOOST_REQUIRE(dict_table.getId("привет") == 1);

}


void test_DictHandler_fillDict_5()
{
    DataHub dh;
    std::string path = PATH;
    path += "dict.txt"; /// file name
    std::ifstream file;


    file.open(path);
    dh.ReadDict(file, " ", ",");
    file.close();

    // set an example tokens
    std::vector<token_t> tokens_tmp;
    token_t tmp_words_1, tmp_words_2;
    tmp_words_1.push_back("привет");
    tmp_words_1.push_back("как");
    tmp_words_1.push_back("дела");
    tokens_tmp.push_back(tmp_words_1);
    
    tmp_words_2.push_back("хорошо");
    tmp_words_2.push_back("а");
    tmp_words_2.push_back("у");
    tmp_words_2.push_back("тебя");
    tokens_tmp.push_back(tmp_words_2);

    dh.setTokens(tokens_tmp);

    DictHandler dict_table;
    dict_table.fitModel(dh);

    BOOST_REQUIRE(dh.getDict()[2].word == "дела");
}


void test_DictHandler_fillDict_6()
{
    DataHub dh;
    std::string path = PATH;
    path += "dict.txt"; /// file name
    std::ifstream file;


    file.open(path);
    dh.ReadDict(file, " ", ",");
    file.close();

    // set an example tokens
    std::vector<token_t> tokens_tmp;
    token_t tmp_words_1, tmp_words_2;
    tmp_words_1.push_back("привет");
    tmp_words_1.push_back("как");
    tmp_words_1.push_back("дела");
    tokens_tmp.push_back(tmp_words_1);
    
    tmp_words_2.push_back("хорошо");
    tmp_words_2.push_back("а");
    tmp_words_2.push_back("у");
    tmp_words_2.push_back("тебя");
    tokens_tmp.push_back(tmp_words_2);

    dh.setTokens(tokens_tmp);

    DictHandler dict_table;
    dict_table.fitModel(dh);

    BOOST_REQUIRE(dh.getSents_id()[1].word_id[0] == 4);
}
