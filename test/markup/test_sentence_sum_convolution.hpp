#ifndef TEST_MARKUP_SENTENCE_SUM_CONVOLUTION_HPP
#define TEST_MARKUP_SENTENCE_SUM_CONVOLUTION_HPP

#include <boost/test/unit_test.hpp>
#include <markup/sentence_sum_convolution.hpp>

BOOST_AUTO_TEST_SUITE(TestSentenceSumConvolutionApplyTo)

    BOOST_AUTO_TEST_CASE(Correct) {
        common::vectorized_word_t w1(2);
        w1[0] = 1.0; w1[1] = 0.0;
        common::vectorized_word_t w2(2);
        w2[0] = 0.0; w2[1] = 1.0;

        common::vectorized_sentence_t s(2);
        s[0] = w1; s[1] = w2;

        auto conv = markup::SentenceSumConvolution();
        auto result = conv.ApplyTo(s);

        BOOST_CHECK_CLOSE(result[0], 1.0, EPS);
        BOOST_CHECK_CLOSE(result[1], 1.0, EPS);
    }

BOOST_AUTO_TEST_SUITE_END()

#endif //TEST_MARKUP_SENTENCE_SUM_CONVOLUTION_HPP