#ifndef MARKUP_VECTOR_OPERATIONS_HPP
#define MARKUP_VECTOR_OPERATIONS_HPP

#include <common/types.hpp>

namespace markup {
    /**
     * Предоставляет методы для сравнения векторизованных слов.
     */
    class VectorizedWordsComparator {
        public:
            VectorizedWordsComparator() = default;
            VectorizedWordsComparator(const VectorizedWordsComparator &comparator) = default;
            VectorizedWordsComparator(VectorizedWordsComparator &&comparator) noexcept = default;

            virtual ~VectorizedWordsComparator() noexcept = default;

            VectorizedWordsComparator& operator =(const VectorizedWordsComparator &comparator) = default;
            VectorizedWordsComparator& operator =(VectorizedWordsComparator &&comparator) noexcept = default;

            /**
             * Сравнивает два слова.
             * @param left
             * Первое слово.
             * @param right
             * Второе слово.
             * @return
             * Коэффициент близости слов 0 <= k <= 1.
             */
            virtual double ApplyTo(const common::vectorized_word_t &left,
                                   const common::vectorized_word_t &right) = 0;
    };
}

#endif //MARKUP_VECTOR_OPERATIONS_HPP
