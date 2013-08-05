#define BOOST_TEST_MODULE environment
#include <boost/test/unit_test.hpp>

#include <bunsan/testing/environment.hpp>

#include <boost/filesystem/operations.hpp>

BOOST_AUTO_TEST_SUITE(testing)

BOOST_AUTO_TEST_CASE(environment)
{
    BOOST_CHECK(boost::filesystem::exists(bunsan::testing::dir::source()));
    BOOST_CHECK(boost::filesystem::exists(bunsan::testing::dir::binary()));
    BOOST_CHECK(boost::filesystem::exists(bunsan::testing::dir::tests::source()));
    BOOST_CHECK(boost::filesystem::exists(bunsan::testing::dir::tests::binary()));
}

BOOST_AUTO_TEST_SUITE_END() // testing
