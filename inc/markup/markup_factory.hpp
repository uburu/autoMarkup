#ifndef MARKUP_MARKUP_FACTORY_HPP
#define MARKUP_MARKUP_FACTORY_HPP

#include "abstract_markup_factory.hpp"
#include "cos_words_comparator.hpp"
#include "sentence_sum_convolution.hpp"

namespace markup {
    /**
     * Способ проведения разметки.
     */
    enum class MarkupType {
        COMMON, SEQUENTIAL, FAST
    };

    typedef markup::CosWordsComparator basic_words_comparator_t;
    typedef markup::SentenceSumConvolution basic_sentence_convolution_t;

    /**
     * Предоставляет методы для создания экземпляра
     * абстрактного класса Markup на основании способа
     * проведения разметки.
     */
    class MarkupFactory : public AbstractMarkupFactory<basic_words_comparator_t,
            basic_sentence_convolution_t> {
        public:
            MarkupFactory() = delete;
            explicit MarkupFactory(MarkupType type);
            MarkupFactory(const MarkupFactory &factory) = default;
            MarkupFactory(MarkupFactory &&factory) noexcept = default;

            ~MarkupFactory() noexcept override = default;

            MarkupFactory& operator =(const MarkupFactory &factory) = default;
            MarkupFactory& operator =(MarkupFactory &&factory) noexcept = default;

            /**
             * Cоздает экземпляр абстрактного класса Markup.
             */
            std::shared_ptr<Markup<basic_words_comparator_t,
                    basic_sentence_convolution_t>> Create() override;

        protected:
            MarkupType markupType;
    };
}

#endif //MARKUP_MARKUP_FACTORY_HPP
