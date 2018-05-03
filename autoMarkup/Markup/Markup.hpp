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
         * Косинусное расстояние между векторами предложений.
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
         * -1, если тексты противоположны по смыслу;
         *  1, если тексты близки по смыслу;
         *  0, если тексты не противоположны и не близки по смыслу.
         */
        virtual int MarkupTexts(const vectorized_text_t &firstText,
                        const vectorized_text_t &secondText,
                        size_t firstWindowSize, size_t secondWindowSize);
};

#endif /* Markup_hpp */
