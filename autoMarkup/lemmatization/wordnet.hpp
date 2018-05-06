// http://www.mkurnosov.net/teaching/uploads/DSA/dsa-fall2013-lec4.pdf - пример префиксного дерева

#ifndef WORDNET_HPP
#define WORDNET_HPP

#include <iostream>
#include <vector>
#include <string>

class WordNet
{
public:
	WordNet();
	void insert(const std::string& word, const std::string& lemma); // метод вставки в дерево
	std::string* find_lemma_of_word(const std::string& word); // поиск нормальной формы слова в дереве

private:


	struct TreeNode {
		char letter = '0'; // имя узла - буква из слова
		/*
		lemma - указатель на нормальную словоформу из lemmas. Присваивается когда доходим до последней буквы в слове
		то есть путь для построения слова записан в дерево и в качестве терминального знака(как в конечных автоматах)
		последняя буква слова указывает на нормальную словоформу
		*/
		std::string* lemma = nullptr;
		std::vector<TreeNode*> childLetters; // вектор указателей на следующие узлы(буквы которые могут идти после текущей буквы)
	};

	/*
	в словаре разным словам может соответствовать одна словоформа, поэтому в целях экономии памяти лучше сделать так,
	чтобы разные слова указывали на одну словоформу, а не так чтобы разные слова дублировали в себе одну и ту же словоформу
	*/
	std::vector<std::string*> lemmas; // вектор указателей на нормальные словоформы
	TreeNode* root = nullptr;
	std::string* findLemma(const std::string& lemWord); // возвращает указатель на словоформу из lemmas, если таковой нет - создает ее
	bool findLetterPtr(const char key, const std::vector<WordNet::TreeNode*>& ptrs); // проверка наличия указателя на узел с именем key(буква из слова) в childLetters
	TreeNode* getLetterPtr(const char key, const std::vector<WordNet::TreeNode*>& ptrs); // получение указателя на узел с именем key(буква из слова) в childLetters
};

#endif // WORDNET_HPP
