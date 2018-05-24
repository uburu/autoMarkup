#include <cassert>
#include <cmath>

#include <common/types.hpp>
#include <markup/cos_words_comparator.hpp>

double markup::CosWordsComparator::ApplyTo(const common::vectorized_word_t &left,
                                                     const common::vectorized_word_t &right) {
    assert(!left.empty() && !right.empty());
    assert(left.size() == right.size());

    double comp = 0.0;
    double sqrLeft = 0.0, sqrRight = 0.0;

    for (size_t i = 0; i < left.size(); ++i) {
        comp += left[i] * right[i];
        sqrLeft += left[i] * left[i];
        sqrRight += right[i] * right[i];
    }

    // assert( (sqrt(sqrLeft) * sqrt(sqrRight)) != 0 );
    double denominator = sqrt(sqrLeft) * sqrt(sqrRight);
    if (denominator == 0) 
        denominator += 0.001; // add noise
    return comp / denominator;
}
