#include "DataHub.hpp"


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
