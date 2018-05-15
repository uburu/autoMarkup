#ifndef MARKUP_MARKUP_HPP
#define MARKUP_MARKUP_HPP

#include <cassert>
#include <common/types.hpp>

#include "words_comparator.hpp"
#include "sentence_convolution.hpp"

namespace markup {
    /**
     * Предоставляет методы для разметки текста на смысловую близость.
     */
    template <typename C = WordsComparator,
            typename CV = SentenceConvolution>
    class Markup {
        public:
            virtual ~Markup() noexcept = default;

            /**
             * Определяет смысловую близость двух векторизованных предложений.
             * @param firstSent
             * Первое предложение в векторизованном виде.
             * @param secondSent
             * Второе предложение в векторизованном виде.
             * @return
             * Коэффициент близости двух векторов: 0 <= k <= 1.
             */
            virtual double MarkupSentences(const common::vectorized_sentence_t &firstSent,
                                           const common::vectorized_sentence_t &secondSent);

            /**
             * Определяет смысловую близость двух векторизованных текстов.
             * @param firstText
             * Первый текст в векторизованном виде.
             * @param secondText
             * Второй текст в векторизованном виде.
             * @param firstWindowSize
             * Размер "окна" в первом тексте.
             * @param secondWindowSize
             * Размер "окна" во втором тексте.
             * @return
             * Коэффициент близости двух текстов: 0 <= k <= 1.
             */
            virtual double MarkupTexts(const common::vectorized_text_t &firstText,
                                       const common::vectorized_text_t &secondText,
                                       size_t firstWindowSize, size_t secondWindowSize) = 0;

        protected:
            C wordsComparator{};
            CV sentenceConvolution{};
    };

    template<typename C, typename CV>
    double Markup<C, CV>::MarkupSentences(const common::vectorized_sentence_t &firstSent,
                                          const common::vectorized_sentence_t &secondSent) {
        assert(firstSent.size() == secondSent.size());
        auto firstSentConv = sentenceConvolution.ApplyTo(firstSent);
        auto secondSentConv = sentenceConvolution.ApplyTo(secondSent);
        return wordsComparator.ApplyTo(firstSentConv, secondSentConv);
    }
}

#endif /* Markup_hpp */
