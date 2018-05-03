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

        int MarkupSentences(const vectorized_sent_t &firstSent,
                            const vectorized_sent_t &secondSent);

        int MarkupTexts(const vectorized_text_t &firstSent,
                        const vectorized_sent_t &secondSent,
                        size_t firstWindowSize, size_t secondWindowSize);
};

#endif /* Markup_hpp */
