#include <boost/test/unit_test.hpp>
#include <markup/cos_vectorized_words_comparator.hpp>

const double EPS = 0.1;

BOOST_AUTO_TEST_SUITE(TestApplyTo)

    BOOST_AUTO_TEST_CASE(RightAngle) {
        common::vectorized_word_t w1(2);
        w1[0] = 1.0; w1[1] = 0.0;

        common::vectorized_word_t w2(2);
        w2[0] = 0.0; w2[1] = 1.0;

        auto cmp = markup::CosVectorizedWordsComparator();
        BOOST_CHECK_CLOSE(cmp.ApplyTo(w1, w2), 0.0, EPS);
    }

    BOOST_AUTO_TEST_CASE(ZeroAngle) {
            common::vectorized_word_t w(2);
            w[0] = 1.0; w[1] = 0.0;

            auto cmp = markup::CosVectorizedWordsComparator();
            BOOST_CHECK_CLOSE(cmp.ApplyTo(w, w), 1.0, EPS);
    }

    BOOST_AUTO_TEST_CASE(Angle45) {
            common::vectorized_word_t w1(2);
            w1[0] = 1.0; w1[1] = 0.0;

            common::vectorized_word_t w2(2);
            w2[0] = 1.0; w2[1] = 1.0;

            auto cmp = markup::CosVectorizedWordsComparator();
            BOOST_CHECK_CLOSE(cmp.ApplyTo(w1, w2), 0.7071, EPS);
    }

    BOOST_AUTO_TEST_CASE(Angle180) {
        common::vectorized_word_t w1(2);
        w1[0] = 1.0; w1[1] = 0.0;

        common::vectorized_word_t w2(2);
        w2[0] = -1.0; w2[1] = 0.0;

        auto cmp = markup::CosVectorizedWordsComparator();
        BOOST_CHECK_CLOSE(cmp.ApplyTo(w1, w2), -1.0, EPS);
    }

BOOST_AUTO_TEST_SUITE_END()