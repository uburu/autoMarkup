#include <cassert>
#include <markup/sentence_sum_convolution.hpp>

common::vectorized_word_t markup::SentenceSumConvolution
        ::ApplyTo(const common::vectorized_sentence_t &sentence) {
    assert(!sentence.empty());
    common::vectorized_word_t sumWord(sentence[0]);

    for (size_t i = 1; i < sentence.size(); ++i) {
        assert(sumWord.size() == sentence[i].size());
        for (size_t j = 0; j < sentence[i].size(); ++j) {
            sumWord[j] += sentence[i][j];
        }
    }

    return sumWord;
}
