#ifndef MARKUP_CONCURRENT_MARKUP_HPP
#define MARKUP_CONCURRENT_MARKUP_HPP

#include "markup.hpp"

namespace markup {
    /**
     * Предоставляет методы для последовательной разметки
     * векторизованных текстов на смысловую близость.
     */
    template <typename C = WordsComparator,
            typename CV = SentenceConvolution>
    class ConcurrentMarkup : public Markup<C, CV> {
        public:
            ConcurrentMarkup() = default;
            ConcurrentMarkup(const ConcurrentMarkup &markup) = default;
            ConcurrentMarkup(ConcurrentMarkup &&markup) noexcept = default;

            ~ConcurrentMarkup() noexcept override = default;

            ConcurrentMarkup& operator =(const ConcurrentMarkup &markup) = default;
            ConcurrentMarkup& operator =(ConcurrentMarkup &&markup) noexcept = default;

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
    double ConcurrentMarkup<C, CV>::MarkupTexts(const common::vectorized_text_t &firstText,
                                                const common::vectorized_text_t &secondText,
                                                size_t firstWindowSize, size_t secondWindowSize) {
        return 0;
    }
}

#endif //MARKUP_CONCURRENT_MARKUP_HPP
