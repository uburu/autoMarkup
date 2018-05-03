#include <cassert>
#include "Markup.hpp"

vectorized_word_t sum_words(const vectorized_sent_t &sent);

double Markup::MarkupSentences(const vectorized_sent_t &firstSent,
                            const vectorized_sent_t &secondSent) {
    auto firstSentVec = sum_words(firstSent);
    auto secondSentVec = sum_words(secondSent);
    return CosCounter().ApplyTo(firstSentVec, secondSentVec);
}

int Markup::MarkupTexts(const vectorized_text_t &firstText,
                        const vectorized_text_t &secondText,
                        size_t firstWindowSize, size_t secondWindowSize) {
    double textCos = 0.0;
    for (size_t firstIndex = 0, secondIndex = 0;
            firstIndex < firstText.size() && secondIndex < secondText.size();
            firstIndex += firstWindowSize, secondIndex += secondWindowSize) {
        for (size_t firstCounter = 0; firstCounter < firstWindowSize; ++firstCounter) {
            for (size_t secondCounter = 0; secondCounter < secondWindowSize; ++secondCounter) {
                double curCos = MarkupSentences(firstText[firstIndex + firstCounter],
                        secondText[secondIndex + secondCounter]);
                textCos = std::max(textCos, curCos);
            }
        }
    }
    return textCos > 0 ? 1 : -1;
}

vectorized_word_t sum_words(const vectorized_sent_t &sent) {
    assert(!sent.empty());
    vectorized_word_t result(sent[0]);
    for (size_t i = 1; i < sent.size(); ++i) {
        assert(result.size() == sent[i].size());
        for (size_t j = 0; j < sent[i][j]; ++j) {
            result[j] += sent[i][j];
        }
    }
    return result;
}
