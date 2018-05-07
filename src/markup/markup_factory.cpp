#include <common/types.hpp>
#include <markup/markup_factory.hpp>
#include <markup/sequential_markup.hpp>

markup::MarkupFactory::MarkupFactory(markup::MarkupType type)
        : markupType(type) {
}

std::shared_ptr<markup::Markup> markup::MarkupFactory::Create() {
    switch (markupType) {
        case MarkupType::SEQUENTIAL:
            return std::make_shared<SequentialMarkup>();

        case MarkupType::CONCURRENT:
            throw common::NotImplementedException("markup::MarkupFactory::Create");
    }
}
