#include <common/types.hpp>
#include <markup/markup_factory.hpp>

#include <markup/sequential_markup.hpp>
#include <markup/fast_markup.hpp>

markup::MarkupFactory::MarkupFactory(markup::MarkupType type)
        : markupType(type) {
}

std::shared_ptr<markup::Markup<markup::basic_words_comparator_t,
        markup::basic_sentence_convolution_t>> markup::MarkupFactory::Create() {
    switch (markupType) {
        case MarkupType::COMMON: case MarkupType::SEQUENTIAL:
            return std::make_shared<SequentialMarkup<basic_words_comparator_t,
                    basic_sentence_convolution_t>>();

        case MarkupType::FAST:
            return std::make_shared<FastMarkup<basic_words_comparator_t,
                    basic_sentence_convolution_t>>();
    }
}
