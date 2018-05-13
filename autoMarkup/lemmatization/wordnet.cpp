#include "wordnet.hpp"


WordNet::WordNet()
{}

// возвращает нужную нормальную словоформу, если таковой не было найдено - она записывается в вектор нормальных словоформ
std::experimental::optional<std::string> WordNet::findLemma(const std::string& lemWord){ 
	std::vector<std::string>::iterator it;

	it = find(lemmas.begin(), lemmas.end(), lemWord);
	if (it != lemmas.end())
		return *it;
	lemmas.push_back(lemWord);
	return lemWord;
}


/*
не очень понимаю каким образом тут использовать find. Например в функции findLemma 
производится поиск в по vector с элементами типа string, и в функцию find мы можем передать
переменную типа стринг и искать именно ее, но в в функции findLetterPtr я ищу объект структуры TreeNode,
у которого поле letter будет равно key, то есть я не могу в find передать объект структуры TreeNode
*/

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
				return {}
			;
		}
	}
}