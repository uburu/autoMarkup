#ifndef MARKUP_CONCURRENT_MARKUP_HPP
#define MARKUP_CONCURRENT_MARKUP_HPP

#include <future>
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

        private:
            common::vectorized_sentence_t FindTextConvolution(const common::vectorized_text_t &text);
    };

    template<typename C, typename CV>
    double ConcurrentMarkup<C, CV>::MarkupTexts(const common::vectorized_text_t &firstText,
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
    common::vectorized_sentence_t ConcurrentMarkup<C, CV>
            ::FindTextConvolution(const common::vectorized_text_t &text) {
        std::vector<std::future<common::vectorized_word_t>> fut(text.size());
        for (size_t i = 0; i < text.size(); ++i) {
            fut[i] = std::async(std::launch::async, [&]() {
                return Markup<C, CV>::sentenceConvolution.ApplyTo(text[i]);
            });
        }

        common::vectorized_sentence_t conv(text.size());
        for (size_t i = 0; i < text.size(); ++i) {
            conv[i] = std::move(fut[i].get());
        }

        return conv;
    }
}

#endif //MARKUP_CONCURRENT_MARKUP_HPP
