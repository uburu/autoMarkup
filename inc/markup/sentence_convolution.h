#ifndef MARKUP_SENTENCE_CONVOLUTION_HPP
#define MARKUP_SENTENCE_CONVOLUTION_HPP

#include <common/types.hpp>

namespace markup {
    /**
     * Предоставляет методы для свертки векторизованного предложения в слово.
     */
    class SentenceConvolution {
        public:
            SentenceConvolution() = default;
            SentenceConvolution(const SentenceConvolution &sentenceConvolution) = default;
            SentenceConvolution(SentenceConvolution &&sentenceConvolution) noexcept = default;

            virtual ~SentenceConvolution() noexcept = default;

            SentenceConvolution& operator =(const SentenceConvolution &sentenceConvolution) = default;
            SentenceConvolution& operator =(SentenceConvolution &&sentenceConvolution) noexcept = default;

            /**
             * Выполняет свертку векторизованного предложения в слово.
             * @param sentence
             * Векторизованное предложение.
             * @return
             * Векторизованное слово.
             */
            virtual common::vectorized_word_t ApplyTo(const common::vectorized_sentence_t &sentence) = 0;
    };
}

#endif //MARKUP_SENTENCE_CONVOLUTION_HPP
