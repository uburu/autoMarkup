#ifndef TEST_MARKUP_MARKUP_FACTORY_HPP
#define TEST_MARKUP_MARKUP_FACTORY_HPP

#include <boost/test/unit_test.hpp>
#include <markup/markup_factory.hpp>

BOOST_AUTO_TEST_SUITE(TestMarkupFactoryCreate)

    BOOST_AUTO_TEST_CASE(Common) {
        auto type = markup::MarkupType::COMMON;
        auto factory = markup::MarkupFactory(type);
        BOOST_CHECK(factory.Create() != nullptr);
    }

    BOOST_AUTO_TEST_CASE(Sequential) {
        auto type = markup::MarkupType::SEQUENTIAL;
        auto factory = markup::MarkupFactory(type);
        BOOST_CHECK(factory.Create() != nullptr);
    }

    BOOST_AUTO_TEST_CASE(Fast) {
        auto type = markup::MarkupType::FAST;
        auto factory = markup::MarkupFactory(type);
        BOOST_CHECK(factory.Create() != nullptr);
    }

BOOST_AUTO_TEST_SUITE_END()

#endif //TEST_MARKUP_MARKUP_FACTORY_HPP
