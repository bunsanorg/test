#define BOOST_TEST_MODULE ExecTest
#include <boost/test/unit_test.hpp>

#include "bunsan/testing/exec_test.hpp"
#include "bunsan/testing/getenv.hpp"

BOOST_AUTO_TEST_SUITE(testing)

BOOST_AUTO_TEST_CASE(nothing_to_do)
{
    BOOST_CHECK_EQUAL(bunsan::testing::getenv("BOOST_TEST_CATCH_SYSTEM_ERRORS"), "no");
}

BOOST_AUTO_TEST_SUITE_END() // testing
