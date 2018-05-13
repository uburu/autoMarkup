#ifndef TEST_MARKUP_MARKUP_HPP
#define TEST_MARKUP_MARKUP_HPP

#include <fakeit.hpp>
#include <boost/test/unit_test.hpp>

#include <random>

#include <markup/markup.hpp>
#include <markup/sequential_markup.hpp>
#include <markup/fast_markup.hpp>

#include <markup/cos_words_comparator.hpp>
#include <markup/sentence_sum_convolution.hpp>

common::vectorized_word_t create_word();
common::vectorized_sentence_t create_sentence();
common::vectorized_text_t create_text();

BOOST_AUTO_TEST_SUITE(TestMarkupTexts)

    BOOST_AUTO_TEST_CASE(ValidCoeff) {
        auto t1 = create_text();
        auto t2 = create_text();

        typedef markup::CosWordsComparator C;
        typedef markup::SentenceSumConvolution CV;

        markup::SequentialMarkup<C, CV> seqMarkup;
        auto seqCoeff = seqMarkup.MarkupTexts(t1, t2, 10, 2);
        BOOST_CHECK(seqCoeff > -0.01 && seqCoeff < 1.01);

        markup::FastMarkup<C, CV> fastMarkup;
        auto fastCoeff = fastMarkup.MarkupTexts(t1, t2, 10, 2);
        BOOST_CHECK(fastCoeff > -0.01 && fastCoeff < 1.01);
    }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestMarkupSentences)

    BOOST_AUTO_TEST_CASE(NoExceptions) {
        typedef markup::CosWordsComparator C;
        typedef markup::SentenceSumConvolution CV;
        fakeit::Mock<markup::Markup<C, CV>> markup;
    }

BOOST_AUTO_TEST_SUITE_END()

common::vectorized_word_t create_word() {
    const size_t wSize = 5;

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1.0, 10.0);

    return common::vectorized_word_t(wSize, dist(mt));
}

common::vectorized_sentence_t create_sentence() {
    auto size = static_cast<size_t>((rand() % 10) + 1);
    common::vectorized_sentence_t s(size);
    for (size_t i = 0; i < size; ++i) {
        s[i] = create_word();
    }
    return s;
}

common::vectorized_text_t create_text() {
    auto size = static_cast<size_t>((rand() % 10) + 1);
    common::vectorized_text_t t(size);
    for (size_t i = 0; i < size; ++i) {
        t[i] = create_sentence();
    }
    return t;
}

#endif //TEST_MARKUP_MARKUP_HPP
