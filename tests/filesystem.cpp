#define BOOST_TEST_MODULE filesystem
#include <boost/test/unit_test.hpp>

#include "bunsan/testing/filesystem/tempdir.hpp"

#include <boost/filesystem/operations.hpp>

BOOST_AUTO_TEST_SUITE(testing)

BOOST_AUTO_TEST_SUITE(filesystem)

BOOST_AUTO_TEST_CASE(tempdir)
{
    boost::filesystem::path path;
    {
        bunsan::testing::filesystem::tempdir tmp;
        path = tmp.path;
        BOOST_REQUIRE(boost::filesystem::exists(path));
    }
    BOOST_CHECK(!boost::filesystem::exists(path));
    if (boost::filesystem::exists(path))
        BOOST_REQUIRE(boost::filesystem::remove(path));
}

BOOST_AUTO_TEST_SUITE_END() // filesystem

BOOST_AUTO_TEST_SUITE_END() // testing
