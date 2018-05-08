#ifndef SEQUENTIAL_MARKUP_HPP
#define SEQUENTIAL_MARKUP_HPP

#include "markup.hpp"

namespace markup {
    /**
     * Предоставляет методы для последовательной разметки
     * векторизованных текстов на смысловую близость.
     */
    template <typename C = WordsComparator,
            typename CV = SentenceConvolution>
    class SequentialMarkup : public Markup<C, CV> {
        public:
            SequentialMarkup() = default;
            SequentialMarkup(const SequentialMarkup &markup) = default;
            SequentialMarkup(SequentialMarkup &&markup) noexcept = default;

            ~SequentialMarkup() noexcept override = default;

            SequentialMarkup& operator =(const SequentialMarkup &markup) = default;
            SequentialMarkup& operator =(SequentialMarkup &&markup) noexcept = default;

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
            double MarkupTexts(const common::vectorized_text_t &firstText,
                               const common::vectorized_text_t &secondText,
                               size_t firstWindowSize, size_t secondWindowSize) override;
    };

    template<typename C, typename CV>
    double SequentialMarkup<C, CV>::MarkupTexts(const common::vectorized_text_t &firstText,
                                                const common::vectorized_text_t &secondText,
                                                size_t firstWindowSize, size_t secondWindowSize) {
        double simCoeff = 0.0;
        for (size_t firstIndex = 0, secondIndex = 0;
                firstIndex < firstText.size() && secondIndex < secondText.size();
                firstIndex += firstWindowSize, secondIndex += secondWindowSize) {
            for (size_t firstCounter = 0; firstCounter < firstWindowSize; ++firstCounter) {
                for (size_t secondCounter = 0; secondCounter < secondWindowSize; ++secondCounter) {
                    double curSimCoeff = this->MarkupSentences(firstText[firstIndex + firstCounter],
                            secondText[secondIndex + secondCounter]);
                    simCoeff = std::max(simCoeff, curSimCoeff);
                }
            }
        }
        return simCoeff;
    }
}

#endif //SEQUENTIAL_MARKUP_HPP
