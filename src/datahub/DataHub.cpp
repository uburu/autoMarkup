#include "DataHub.hpp"

void DataHub::SetText(const std::string& tx){
    text = tx;
}

void DataHub::SetSentences(const std::vector<std::string>& s) {
    sentences = s;
}

void DataHub::SetTokens(const std::vector<token_t>& t) {
    tokens = t;
}


void DataHub::SetLemmaTokens(const std::vector<std::vector<std::experimental::optional<std::string>>>& lt) {
    lemma_tokens = lt;
}

void DataHub::SetDict(const std::vector<dictelem_t>& d)
{
    dict = d;
}


void DataHub::SetSentsId(const std::vector<word2id_t>& si)
{
    sents_id = si;
}


void DataHub::SetSentsEmbeddings(const std::vector<id2vector_t>& se)
{
    sents_embeddings = se;
}



void DataHub::ShowContent() {
    std::cout << "\n\n-------------SEPARATION ON SENTECES TEST------------------------\n\n";
    for (auto sentence : sentences) {
        std::cout << sentence << "\n";
    }
    std::cout << "\n\n-------------SEPARATION SENTECES ON WORDS TEST------------------------\n\n";

    for (auto sentence : tokens) {
        for (auto word : sentence) {
            std::cout << word << " ";
        }
        std::cout << "\n\n";
    }
    std::cout << "\n\n-------------LEMMAS------------------------\n\n";
    for (auto sentence : lemma_tokens){
        for (auto word : sentence){
            std::cout << word.value() << " ";
        }
        std::cout << "\n\n";
    }
}
