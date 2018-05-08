#ifndef SEQUENTIAL_MARKUP_HPP
#define SEQUENTIAL_MARKUP_HPP

#include "markup.hpp"
#include "abstract_markup_factory.hpp"

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
                                                const common::vectorized_text_t &secondText, size_t firstWindowSize,
                                                size_t secondWindowSize) {
        throw common::NotImplementedException("markup::SequentialMarkup::MarkupTexts");
    }
}

#endif //SEQUENTIAL_MARKUP_HPP
