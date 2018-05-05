#include "wordnet.hpp"


WordNet::WordNet()
{}

// возвращает нужную нормальную словоформу, если таковой не было найдено - она записывается в вектор нормальных словоформ
std::string* WordNet::findLemma(const std::string& lemWord){ 
	for (int i = 0; i < lemmas.size(); i++){
		if (*lemmas[i] == lemWord){
			// std::cout << "ADDRES OF LEMMA: " << *lemmas[i] << "\n";
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
	// std::cout << "LET: " << root->childLetters[0]->letter;
	TreeNode* curNode = root;
	for (int i = 0; i < word.size(); i++){
		// std::string nodeName = word[i]; // word[i] - переменная типа char 
		if (!findLetterPtr(word[i], curNode->childLetters)){ // если такой буквы еще нет на этом пути
			// std::cout << " word[i]: " << &word[i] << "\n";
			TreeNode* newNode = new TreeNode;
			newNode->letter = word[i];
			if (i == (word.size() - 1)){
				newNode->lemma = findLemma(lemWord);
				// std::cout << "LEMMA: " << lemWord << "\n";
			} // если дошли до последней буквы слова - присваиваем этой букве указатель на словоформу
			// std::cout << "LETTER: " << curNode->letter;
			// std::cout << "LEMMA: " << &curNode->lemma << "\n";
			// std::cout << ""
			curNode->childLetters.push_back(newNode); 
			curNode = newNode; // спускаемся на уровень где будет рассматриваться следующая буква слова
		}
		else{ // если такая буква уже есть на этом пути
			curNode = getLetterPtr(word[i], curNode->childLetters);
		}
		// std::cout << "LETTER: " << curNode->letter << "\n";
		// if (curNode->lemma != nullptr)
		// {
		// 	std::cout << "LEMMA: " << *curNode->lemma << "\n";
		// 	std::cout << "ADDR LEMMA: " << curNode->lemma << "\n";
		// }


	}
}


std::string* WordNet::find_lemma_of_word(const std::string& word){ // поиск леммы по слову
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
