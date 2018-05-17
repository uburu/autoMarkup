#ifndef MARKUP_ABSTRACT_MARKUP_FACTORY_HPP
#define MARKUP_ABSTRACT_MARKUP_FACTORY_HPP

#include <memory>
#include <markup/markup.hpp>

namespace markup {
    /**
     * Предоставляет методы для создания экземпляра
     * абстрактного класса Markup.
     */
    template <typename C = WordsComparator,
            typename CV = SentenceConvolution>
    class AbstractMarkupFactory {
        public:
            virtual ~AbstractMarkupFactory() noexcept = default;

            /**
             * Cоздает экземпляр абстрактного класса Markup.
             */
            virtual std::shared_ptr<Markup<C, CV>> Create() = 0;
    };
}

#endif //MARKUP_ABSTRACT_MARKUP_FACTORY_HPP
