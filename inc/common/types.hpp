#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H

#include <vector>
#include <string>
#include <utility>
#include "exceptions.hpp"

namespace common {
    /**
     * Векторизованное слово.
     */
    typedef std::vector<double> vectorized_word_t;

    /**
     * Векторизованное предложение.
     */
    typedef std::vector<vectorized_word_t> vectorized_sentence_t;

    /**
     * Векторизованный текст.
     */
    typedef std::vector<vectorized_sentence_t> vectorized_text_t;
}

#endif //COMMON_TYPES_H
