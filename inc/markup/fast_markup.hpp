#ifndef MARKUP_FAST_MARKUP_HPP
#define MARKUP_FAST_MARKUP_HPP

#include "markup.hpp"
#include <algorithm>

namespace markup {
    /**
     * Предоставляет методы для быстрой разметки
     * векторизованных текстов на смысловую близость.
     * При этом точность результатов теряется.
     */
    template <typename C = WordsComparator,
            typename CV = SentenceConvolution>
    class FastMarkup : public Markup<C, CV> {
        public:
            FastMarkup() = default;
            FastMarkup(const FastMarkup &markup) = default;
            FastMarkup(FastMarkup &&markup) noexcept = default;

            ~FastMarkup() noexcept override = default;

            FastMarkup& operator =(const FastMarkup &markup) = default;
            FastMarkup& operator =(FastMarkup &&markup) noexcept = default;

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

        private:
            common::vectorized_sentence_t FindTextConvolution(const common::vectorized_text_t &text);
    };

    template<typename C, typename CV>
    double FastMarkup<C, CV>::MarkupTexts(const common::vectorized_text_t &firstText,
                                                const common::vectorized_text_t &secondText,
                                                size_t firstWindowSize, size_t secondWindowSize) {
        assert(!firstText.empty() && !secondText.empty());

        auto firstConv = std::move(FindTextConvolution(firstText));
        auto secondConv = std::move(FindTextConvolution(secondText));

        double simCoeff = 0.0;
        for (size_t index = 0; index < std::min(firstText.size(), secondText.size()); ++index) {
            simCoeff = std::max(simCoeff, this->wordsComparator.ApplyTo(firstConv[index], secondConv[index]));
        }

        return simCoeff;
    }

    template<typename C, typename CV>
    common::vectorized_sentence_t FastMarkup<C, CV>
            ::FindTextConvolution(const common::vectorized_text_t &text) {
        common::vectorized_sentence_t textConv(text.size());
        for (size_t i = 0; i < text.size(); ++i) {
            textConv[i] = std::move(this->sentenceConvolution.ApplyTo(text[i]));
        }
        return textConv;
    }
}

#endif //MARKUP_FAST_MARKUP_HPP
