#ifndef SEQUENTIAL_MARKUP_HPP
#define SEQUENTIAL_MARKUP_HPP

#include "markup.hpp"

namespace markup
{
    class SequentialMarkup : public Markup {
        public:
            SequentialMarkup() = default;
            SequentialMarkup(const SequentialMarkup &markup) = default;
            SequentialMarkup(SequentialMarkup &&markup) noexcept = default;

            ~SequentialMarkup() noexcept override = default;

            SequentialMarkup& operator =(const SequentialMarkup &markup) = default;
            SequentialMarkup& operator =(SequentialMarkup &&markup) noexcept = default;

            double MarkupTexts(const vectorized_text_t &firstText,
                               const vectorized_text_t &secondText,
                               size_t firstWindowSize, size_t secondWindowSize) override;
    };
}

#endif //SEQUENTIAL_MARKUP_HPP
