#include "datasetcreator.hpp"
#include <iostream>

// DataSetCreator::DataSetCreator(const std::shared_ptr<DataHub>& ptr){
// 	hub.reset(new DataHub);
// 	hub = ptr;
// }

void DataSetCreator::createDataSet(const std::string& path, std::vector<std::string> sentences, std::vector<id2vector_t> sents_embeddings, double threshold){
	
	assert(sentences.size() == sents_embeddings.size());
	std::ofstream output;
	output.open(path);
	auto sentSize = sentences.size();
	auto markup_v = markup::MarkupFactory(markup::MarkupType::COMMON).Create();
	double label = 0;
	double cosin = 0;

	const std::string delim = "|";


	output << "id" << delim <<"sentence_1" << delim << "sentence_2" << delim << "label\n";
	for (int i = 0; i < sentSize - 1; i++)
	{
		if (sents_embeddings[i+1].word_embeddings.empty() || sents_embeddings[i].word_embeddings.empty()) 
		{
			i += 1;

			// std::cout << "empty word_embeddings index + 1 = " << i+1  << " len = " << sents_embeddings[i+1].word_embeddings.size() << "\n";
			// std::cout << "sent[i+1]: " << sentences[i+1] << "\n";
			// std::cout << "sent[i+2]: " << sentences[i+2] << "\n";
			
			continue;
		}
		if (sents_embeddings[i].word_embeddings.empty()) std::cout << "empty word_embeddings index = " << i << "\n";
	
		cosin = markup_v->MarkupSentences(sents_embeddings[i].word_embeddings, sents_embeddings[i+1].word_embeddings);
		label = 0;
		if (cosin > threshold)
			label = 1;
		output << i << delim << sentences[i] << delim << sentences[i+1] << delim << label << "\n";
	}

	output.close();
}