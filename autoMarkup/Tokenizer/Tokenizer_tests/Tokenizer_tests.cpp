#include "../Tokenizer.hpp"
#include "../../lemmatization/traincontroller.hpp"
#include <iostream>
#include <fstream>


int main()
{

	// Traincontroller ac;
	// ac.run();

	Tokenizer t;
	std::ifstream fin("test_text.txt");
	std::cout << "-------------READ TEST------------------------\n\n";
	t.ReadText(fin);
	std::cout << "\n\n-------------SEPARATION ON SENTECES TEST------------------------\n\n";
	t.sentence_token();
	std::cout << "\n\n-------------SEPARATION SENTECES ON WORDS TEST------------------------\n\n";
	t.sentence_to_words();
	std::cout << "\n\n-------------LEMMAS------------------------\n\n";
	t.tokens_to_lemma();
	// std::cout << t.text << "\n";
	return 0;
}
