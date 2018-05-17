#ifndef MARKUP_SENTENCE_SUM_CONVOLUTION_HPP
#define MARKUP_SENTENCE_SUM_CONVOLUTION_HPP

#include "sentence_convolution.hpp"

namespace markup {
    class SentenceSumConvolution : public SentenceConvolution {
        public:
            SentenceSumConvolution() = default;
            SentenceSumConvolution(const SentenceSumConvolution &convolution) = default;
            SentenceSumConvolution(SentenceSumConvolution &&convolution) noexcept = default;

            ~SentenceSumConvolution() noexcept override = default;

            SentenceSumConvolution& operator =(const SentenceSumConvolution &convolution) = default;
            SentenceSumConvolution& operator =(SentenceSumConvolution &&convolution) noexcept = default;

            common::vectorized_word_t ApplyTo(const common::vectorized_sentence_t &sentence) override;
    };
}

#endif //MARKUP_SENTENCE_SUM_CONVOLUTION_HPP
