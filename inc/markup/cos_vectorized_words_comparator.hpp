#ifndef MARKUP_COS_VECTORIZED_WORDS_COMPARATOR_HPP
#define MARKUP_COS_VECTORIZED_WORDS_COMPARATOR_HPP

#include "vectorized_words_comparator.hpp"

namespace markup {
    /**
     * Предоставляет методы для сравнения векторизованных слов
     * на основании косинусного расстояния между ними.
     */
    class CosVectorizedWordsComparator : public VectorizedWordsComparator {
        public:
            CosVectorizedWordsComparator() = default;
            CosVectorizedWordsComparator(const CosVectorizedWordsComparator &comparator) = default;
            CosVectorizedWordsComparator(CosVectorizedWordsComparator &&comparator) noexcept = default;

            ~CosVectorizedWordsComparator() noexcept override = default;

            CosVectorizedWordsComparator& operator =(const CosVectorizedWordsComparator &comparator) = default;
            CosVectorizedWordsComparator& operator =(CosVectorizedWordsComparator &&comparator) noexcept = default;

            /**
             * Сравнивает два слова.
             * @param left
             * Первое слово.
             * @param right
             * Второе слово.
             * @return
             * Коэффициент близости слов 0 <= k <= 1.
             */
            double ApplyTo(const common::vectorized_word_t &left,
                           const common::vectorized_word_t &right) override;
    };
}

#endif //MARKUP_COS_VECTORIZED_WORDS_COMPARATOR_HPP
