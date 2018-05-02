#include "wordnet.hpp"


// возвращает нужную нормальную словоформу, если таковой не было найдено - она записывается в вектор нормальных словоформ
std::string* WordNet::findLemma(const string& lemWord){ 
	for (int i = 0; i < lemmas.size(); i++){
		if (*lemmas[i] == lemWord)
			return *lemmas[i];
	}
	std::string* newLemma = new std::string(lemWord);
	lemmas.push_back(newLemma);
	return newLemma;
}

// проверка наличия узла с нужной буквой в массиве дочерних букв
bool WordNet::findLetterPtr(const string& key, const vector<TreeNode*>& ptrs){ 
	for (int i = 0; i < ptrs.size(); i++){
		if ptrs[i]->letter == key
			return true;
	}
	return false;
}


// получение указателя на узел с искомой буквой
TreeNode* WordNet::getLetterPtr(const string& key, const vector<TreeNode*>& ptrs){
	for (int i = 0; i < ptrs.size(); i++){
		if ptrs[i]->letter == key
			return ptrs[i];
	}
	return nullptr;
}


void WordNet::insert(const string& word, const string& lemWord){
	if (root == nullptr){
		root = new TreeNode;
	}
	TreeNode* curNode = root;
	for (int i = 0; i < word.size(); i++){
		if (!findLetterPtr(word[i], curNode->childLetters)){ // если такой буквы еще нет на этом пути
			TreeNode* newNode = new TreeNode;
			newNode->letter = word[i];
			if (i == (word.size() - 1)){
				newNode->lemma = findLemma(lemWord);
			} // если дошли до последней буквы слова - присваиваем этой букве указатель на словоформу
			curNode->childLetters.push_back(newNode); 
			curNode = newNode; // спускаемся на уровень где будет рассматриваться следующая буква слова
		}
		else{ // если такая буква уже есть на этом пути
			curNode = getLetterPtr(word[i], curNode->childLetters);
		}
	}
}