#include "wordnet.hpp"
#include <boost/bind.hpp>

WordNet::WordNet()
{}

// возвращает нужную нормальную словоформу, если таковой не было найдено - она записывается в вектор нормальных словоформ
std::experimental::optional<std::string> WordNet::findLemma(const std::string& lemWord){ 
	auto it = find(lemmas.begin(), lemmas.end(), lemWord);
	if (it != lemmas.end())
		return *it;
	lemmas.push_back(lemWord);
	return lemWord;
}

// проверка наличия узла с нужной буквой в массиве дочерних букв
bool WordNet::findLetterPtr(const char key, const std::vector<WordNet::TreeNode*>& ptrs){
	if (find_if(ptrs.begin(), ptrs.end(), boost::bind( &TreeNode::getNodename, _1 ) == key ) != ptrs.end() )
		return true;
	return false;
}


WordNet::TreeNode* WordNet::getLetterPtr(const char key, const std::vector<WordNet::TreeNode*>& ptrs){
	return *find_if(ptrs.begin(), ptrs.end(), boost::bind( &TreeNode::getNodename, _1 ) == key );
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


std::experimental::optional<std::string> WordNet::find_lemma_of_word(const std::string& word){
	if (root == nullptr){
		return {};
	}
	else{
		TreeNode* curNode = root;
		for (int i = 0; i < word.size(); i++){
			if (findLetterPtr(word[i], curNode->childLetters)){
				curNode = getLetterPtr(word[i], curNode->childLetters);
				if (i == (word.size()-1) && curNode->lemma){
					return curNode->lemma.value();
				}
			}
			else 
				return {};
		}
	}
}