#ifndef MARKUP_COS_WORDS_COMPARATOR_HPP
#define MARKUP_COS_WORDS_COMPARATOR_HPP

#include "words_comparator.hpp"

namespace markup {
    /**
     * Предоставляет методы для сравнения векторизованных слов
     * на основании косинусного расстояния между ними.
     */
    class CosWordsComparator : public WordsComparator {
        public:
            CosWordsComparator() = default;
            CosWordsComparator(const CosWordsComparator &comparator) = default;
            CosWordsComparator(CosWordsComparator &&comparator) noexcept = default;

            ~CosWordsComparator() noexcept override = default;

            CosWordsComparator& operator =(const CosWordsComparator &comparator) = default;
            CosWordsComparator& operator =(CosWordsComparator &&comparator) noexcept = default;

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

#endif //MARKUP_COS_WORDS_COMPARATOR_HPP
