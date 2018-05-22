#include "datasetcreator.hpp"


// DataSetCreator::DataSetCreator(const std::shared_ptr<DataHub>& ptr){
// 	hub.reset(new DataHub);
// 	hub = ptr;
// }

void DataSetCreator::createDataSet(const std::string& path, std::vector<std::string> sentences, std::vector<id2vector_t> sents_embeddings){
	std::cout << "???" << "\n";
	std::ofstream output;
	std::cout << "1" << "\n";
	output.open(path);
	std::cout << "2" << "\n";
	std::cout << "LLL" <<sentences.size()<< "\n";
	std::cout << "pppp" << sents_embeddings.size()<< "\n";
	assert(sentences.size() == sents_embeddings.size());
	// std::cout << "!!!!";
	auto sentSize = sentences.size();
	std::cout << "3" << "\n";
	// std::cout << sentences.size()<< "\n";
	// std::cout << sents_embeddings.size()<< "\n";
	auto markup_v = markup::MarkupFactory(markup::MarkupType::COMMON).Create();
	std::cout << "4" << "\n";
	output << "id;sentence_1;sentence_2;label\n";
	std::cout << "5" << "\n";
	for (int i = 0; i < sentSize - 1; i++){
		std::cout << "+ " << sents_embeddings[i].word_embeddings.size() << "  " << sents_embeddings[i+1].word_embeddings.size() << "\n" ;
		auto cosin = markup_v->MarkupSentences(sents_embeddings[i].word_embeddings, sents_embeddings[i+1].word_embeddings);
		output << i << ";" << sentences[i] << ";" << sentences[i+1] << ";" << cosin << "\n";
	}

	output.close();
}