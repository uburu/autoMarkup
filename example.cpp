#include <iostream>
#include "autoMarkup/DataHub/DataHub.hpp"
#include "autoMarkup/DictHandler/DictHandler.hpp"
#include "autoMarkup/Tokenizer/Tokenizer.hpp"


int main(int argc, const char * argv[]) {
   
    std::ifstream file;
    file.open("./data/sents.txt");
    
    DataHub dh;
    dh.ReadText(file);
    
    file.close();

    std::cout << dh.getText() << std::endl;


    file.open("./data/dict.txt");
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

    std::cout << "size of sentences of tokens in DataHub: " << dh.getTokens().size() << std::endl;

    DictHandler dict_table;
    dict_table.fitModel(dh);
    
    

    std::cout << "id of word 'привет': " << dict_table.getId("привет") << std::endl;

    std::cout << "\nword '" << dh.getDict()[2].word << "' has id [2] or 3 in dict.txt " << std::endl;
    std::cout << "1-st word: '" << dh.getTokens()[1][0] << "' from 2-nd sentence has id: " 
    << dh.getSents_id()[1].word_id[0] << std::endl;

    Tokenizer t;
    std::ifstream fin("test_text.txt");
    std::cout << "-------------READ TEST------------------------\n\n";
    t.ReadText(fin);
    std::cout << "\n\n-------------SEPARATION ON SENTECES TEST------------------------\n\n";
    // t.sentence_token();
    std::cout << "\n\n-------------SEPARATION SENTECES ON WORDS TEST------------------------\n\n";
    t.sentence_to_words();
    // std::cout << t.text << "\n";
    
    return 0;
}
