#include "CosCounter.hpp"

#include <cmath>
#include <cassert>

double CosCounter::ApplyTo(const std::vector<double> &first,
                           const std::vector<double> &second) {
    assert(first.size() == second.size());

    double comp = 0.0;
    double sqrFirst = 0.0, sqrSecond = 0.0;

    for (size_t i = 0; i < first.size(); ++i) {
        comp += first[i] * second[i];
        sqrFirst += first[i] * first[i];
        sqrSecond += second[i] * second[i];
    }

    return comp / (sqrt(sqrFirst) + sqrt(sqrSecond));
}
