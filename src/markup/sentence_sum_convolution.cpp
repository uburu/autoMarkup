#include <cassert>
#include <markup/sentence_sum_convolution.hpp>
#include <iostream>

common::vectorized_word_t markup::SentenceSumConvolution
        ::ApplyTo(const common::vectorized_sentence_t &sentence) {
    // assert(!sentence.empty());
    if (sentence.empty())
    {
        common::vectorized_word_t tmp(sentence[0]);
        for (size_t i = 0; i < tmp.size(); i ++)
            tmp[i] = 1;
        std::cout << "empty_sent, len of tmp = " << tmp.size() << " \n array[0] = " << tmp[0] << "\n";
        // for (auto i: tmp)
        //     std::cout << i << " ";
        // std::cout << "\n";

        return tmp;
    }
    common::vectorized_word_t sumWord(sentence[0]);

    for (size_t i = 1; i < sentence.size(); ++i) {
        assert(sumWord.size() == sentence[i].size());
        for (size_t j = 0; j < sentence[i].size(); ++j) {
            sumWord[j] += sentence[i][j];
        }
    }

    return sumWord;
}
