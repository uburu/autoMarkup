#ifndef MARKUP_MARKUP_FACTORY_HPP
#define MARKUP_MARKUP_FACTORY_HPP

#include <markup/markup.hpp>

namespace markup {
    /**
     * Предоставляет метод для создания экземпляра
     * абстрактного класса Markup.
     */
    class MarkupFactory {
        public:
            MarkupFactory() = default;
            MarkupFactory(const MarkupFactory &factory) = default;
            MarkupFactory(MarkupFactory &&factory) noexcept = default;

            virtual ~MarkupFactory() noexcept = default;

            MarkupFactory& operator =(const MarkupFactory &factory) = default;
            MarkupFactory& operator =(MarkupFactory &&factory) noexcept = default;

            /**
             * Cоздает экземпляр абстрактного класса Markup.
             */
            virtual Markup Create() = 0;
    };
}

#endif //MARKUP_MARKUP_FACTORY_HPP
