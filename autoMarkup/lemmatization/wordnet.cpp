#include "wordnet.hpp"


WordNet::WordNet()
{}

// возвращает нужную нормальную словоформу, если таковой не было найдено - она записывается в вектор нормальных словоформ
std::string* WordNet::findLemma(const std::string& lemWord){ 
	for (int i = 0; i < lemmas.size(); i++){
		if (*lemmas[i] == lemWord){
			return lemmas[i];
		}
	}
	std::string* newLemma = new std::string(lemWord);
	lemmas.push_back(newLemma);
	return newLemma;
}

// проверка наличия узла с нужной буквой в массиве дочерних букв
bool WordNet::findLetterPtr(const char key, const std::vector<WordNet::TreeNode*>& ptrs){ 
	for (int i = 0; i < ptrs.size(); i++){
		if (ptrs[i]->letter == key)
			return true;
	}
	return false;
}


// получение указателя на узел с искомой буквой
WordNet::TreeNode* WordNet::getLetterPtr(const char key, const std::vector<WordNet::TreeNode*>& ptrs){
	for (int i = 0; i < ptrs.size(); i++){
		if (ptrs[i]->letter == key){
			return ptrs[i];
		}
	}
	return nullptr;
}


void WordNet::insert(const std::string& word, const std::string& lemWord){
	if (root == nullptr){
		root = new TreeNode;
	}
	TreeNode* curNode = root;
	for (int i = 0; i < word.size(); i++){
		if (!findLetterPtr(word[i], curNode->childLetters)){ // если такой буквы еще нет на этом пути
			TreeNode* newNode = new TreeNode;
			newNode->letter = word[i];
			if (i == (word.size() - 1)){  // если дошли до последней буквы слова - присваиваем этой букве указатель на словоформу
				newNode->lemma = findLemma(lemWord);
			} 
			curNode->childLetters.push_back(newNode); 
			curNode = newNode; // спускаемся на уровень где будет рассматриваться следующая буква слова
		}
		else{ // если такая буква уже есть на этом пути
			curNode = getLetterPtr(word[i], curNode->childLetters);
		}
	}
}



// поиск нормальной формы слова в дереве
std::string* WordNet::find_lemma_of_word(const std::string& word){
	if (root == nullptr){
		return nullptr;
	}
	else{
		TreeNode* curNode = root;
		for (int i = 0; i < word.size(); i++){
			if (findLetterPtr(word[i], curNode->childLetters)){
				// std::cout << "6\n";
				curNode = getLetterPtr(word[i], curNode->childLetters);
				if (i == (word.size()-1) && curNode->lemma != nullptr){
					return curNode->lemma;
				}
			}
			else 
				return nullptr;
		}
	}
}
