#ifndef SEQUENTIAL_MARKUP_HPP
#define SEQUENTIAL_MARKUP_HPP

#include "markup.hpp"

namespace markup
{
    class SequentialMarkup : public Markup {
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
}

#endif //SEQUENTIAL_MARKUP_HPP
