#include "datasetcreator.hpp"


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


	output << "id;sentence_1;sentence_2;label;cosin\n";
	for (int i = 0; i < sentSize - 1; i++){
		cosin = markup_v->MarkupSentences(sents_embeddings[i].word_embeddings, sents_embeddings[i+1].word_embeddings);
		label = 0;
		if (cosin > threshold)
			label = 1;
		output << i << ";" << sentences[i] << ";" << sentences[i+1] << ";" << label << ";" << cosin << "\n";
	}

	output.close();
}