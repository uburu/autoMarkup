#include "Tokenizer.hpp"
#include "traincontroller.hpp"
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
	t.parseToSentenses();
	std::cout << "\n\n-------------SEPARATION SENTECES ON WORDS TEST------------------------\n\n";
	t.parseSentencesToWords();
	std::cout << "\n\n-------------LEMMAS------------------------\n\n";
	t.tokensToLemma();
	// std::cout << t.text << "\n";
	return 0;
}
