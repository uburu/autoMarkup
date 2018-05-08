#ifndef MARKUP_WORDS_COMPARATOR_HPP
#define MARKUP_WORDS_COMPARATOR_HPP

#include <common/types.hpp>

namespace markup {
    /**
     * Предоставляет методы для сравнения векторизованных слов.
     */
    class WordsComparator {
        public:
            virtual ~WordsComparator() noexcept = default;

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

#endif //MARKUP_WORDS_COMPARATOR_HPP
