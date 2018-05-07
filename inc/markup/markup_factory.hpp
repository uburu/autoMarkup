#ifndef MARKUP_MARKUP_FACTORY_HPP
#define MARKUP_MARKUP_FACTORY_HPP

#include <memory>
#include <markup/markup.hpp>

namespace markup {
    /**
     * Предоставляет метод для создания экземпляра
     * абстрактного класса Markup.
     */
    class AbstractMarkupFactory {
        public:
            AbstractMarkupFactory() = default;
            AbstractMarkupFactory(const AbstractMarkupFactory &factory) = default;
            AbstractMarkupFactory(AbstractMarkupFactory &&factory) noexcept = default;

            virtual ~AbstractMarkupFactory() noexcept = default;

            AbstractMarkupFactory& operator =(const AbstractMarkupFactory &factory) = default;
            AbstractMarkupFactory& operator =(AbstractMarkupFactory &&factory) noexcept = default;

            /**
             * Cоздает экземпляр абстрактного класса Markup.
             */
            virtual std::shared_ptr<Markup> Create() = 0;
    };

    /**
     * Способ проведения разметки.
     */
    enum class MarkupType {
        SEQUENTIAL, CONCURRENT
    };

    /**
     * Предоставляет метод для создания экземпляра
     * абстрактного класса Markup на основании способа
     * проведения разметки.
     */
    class MarkupFactory : public AbstractMarkupFactory {
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
            std::shared_ptr<Markup> Create() override;

        protected:
            MarkupType markupType;
    };
}

#endif //MARKUP_MARKUP_FACTORY_HPP
