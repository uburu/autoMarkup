#ifndef COSCOUNTER_H
#define COSCOUNTER_H

#include "Types.hpp"

class CosCounter {
    public:
        CosCounter() = default;
        CosCounter(const CosCounter &cosCounter) = default;
        CosCounter(CosCounter &&cosCounter) noexcept = default;

        virtual ~CosCounter() noexcept = default;

        CosCounter& operator =(const CosCounter &cosCounter) = default;
        CosCounter& operator =(CosCounter &&cosCounter) noexcept = default;

        double ApplyTo(const std::vector<double> &first,
                       const std::vector<double> &second);
};

#endif //COSCOUNTER_H
