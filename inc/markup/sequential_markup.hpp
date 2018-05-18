#ifndef MARKUP_SEQUENTIAL_MARKUP_HPP
#define MARKUP_SEQUENTIAL_MARKUP_HPP

#include "markup.hpp"
#include <algorithm>

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

        protected:
            double MarkupWindows(const common::vectorized_text_t &firstText,
                                 const common::vectorized_text_t &secondText,
                                 size_t firstTextBeginIndex, size_t firstTextEndIndex,
                                 size_t secondTextBeginIndex, size_t secondTextEndIndex);
    };

    template<typename C, typename CV>
    double SequentialMarkup<C, CV>::MarkupTexts(const common::vectorized_text_t &firstText,
                                                const common::vectorized_text_t &secondText,
                                                size_t firstWindowSize, size_t secondWindowSize) {
        assert(!firstText.empty() && !secondText.empty());
        assert(firstWindowSize > 0 && secondWindowSize > 0);

        double simCoeff = 0.0;
        for (size_t i = 0; (i + firstWindowSize) < firstText.size(); i += firstWindowSize) {
            for (size_t j = 0; (j + secondWindowSize) < secondText.size(); j += secondWindowSize) {
                simCoeff = std::max(simCoeff, MarkupWindows(firstText, secondText,
                        i, i + firstWindowSize, j, j + secondWindowSize));
            }
        }

        return simCoeff;
    }

    template<typename C, typename CV>
    double SequentialMarkup<C, CV>::MarkupWindows(const common::vectorized_text_t &firstText,
                                                  const common::vectorized_text_t &secondText,
                                                  size_t firstTextBeginIndex, size_t firstTextEndIndex,
                                                  size_t secondTextBeginIndex, size_t secondTextEndIndex) {
        assert(firstTextBeginIndex >= 0 && firstTextBeginIndex < firstText.size());
        assert(firstTextEndIndex >= 0 && firstTextEndIndex < firstText.size());

        assert(secondTextBeginIndex >= 0 && secondTextBeginIndex < secondText.size());
        assert(secondTextEndIndex >= 0 && secondTextEndIndex < secondText.size());

        double simCoeff = 0.0;
        for (size_t i = firstTextBeginIndex; i <= firstTextEndIndex; ++i) {
            for (size_t j = secondTextBeginIndex; j <= secondTextEndIndex; ++j) {
                simCoeff = std::max(simCoeff, this->MarkupSentences(firstText[i], secondText[j]));
            }
        }

        return simCoeff;
    }
}

#endif //MARKUP_SEQUENTIAL_MARKUP_HPP
