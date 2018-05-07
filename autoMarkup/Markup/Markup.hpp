#ifndef Markup_hpp
#define Markup_hpp

#include "Types.hpp"
#include "CosCounter.hpp"

class Markup {
    public:
        Markup() = default;
        Markup(const Markup &markup) = default;
        Markup(Markup &&markup) noexcept = default;

        virtual ~Markup() noexcept = default;

        Markup& operator =(const Markup &markup) = default;
        Markup& operator =(Markup &&markup) noexcept = default;

        /**
         * Определяет смысловую близость двух векторизованных предложений.
         * @param firstSent
         * Первое предложение в векторизованном виде.
         * @param secondSent
         * Второе предложение в векторизованном виде.
         * @return
         * Коэффициент близости двух векторов: 0 <= k <= 1.
         */
        virtual double MarkupSentences(const vectorized_sent_t &firstSent,
                                       const vectorized_sent_t &secondSent);

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
        virtual double MarkupTexts(const vectorized_text_t &firstText,
                                   const vectorized_text_t &secondText,
                                   size_t firstWindowSize, size_t secondWindowSize);
};

#endif /* Markup_hpp */
