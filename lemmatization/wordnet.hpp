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
	~WordNet();

	void insert(const string& word, const string& lemma);

private:


	struct TreeNode {
		std::string letter = "NAN"; // имя узла - буква из слова
		/*
		lemma - указатель на нормальную словоформу, присваивается когда доходим до последней буквы в слове
		то есть путь для построения слова записан в дерево и качестве терминального знака(как в конечных автоматах)
		последняя буква слова указывает на нормальную словоформу
		*/
		std::string* lemma = nullptr;
		std::vector<TreeNode*> childLetters; // вектор указателей на следующие узлы(буквы которые могут идти после текущей буквы)
	};

	/*
	в словаре разным словам может соответствовать одна словоформа, поэтому в целях экономии памяти лучше сделать так,
	чтобы разные слова указывали на одну словоформу, а не так чтобы разные слова дублировали в себе одну и ту же словоформу
	*/
	std::vector<string*> lemmas; // вектор указателей на нормальные словоформы
	TreeNode* root = nullptr;
	std::string* findLemma(const string& lemWord); // возвращает указатель на словоформу из lemmas, если таковой нет - создает ее
	bool findLetterPtr(const string& key, const vector<TreeNode*>& ptrs); 
	TreeNode* getLetterPtr(const string& key, const vector<TreeNode*>& ptrs);
}

#endif // WORDNET_HPP
