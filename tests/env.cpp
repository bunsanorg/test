#define BOOST_TEST_MODULE env
#include <boost/test/unit_test.hpp>

#include <bunsan/testing/getenv.hpp>
#include <bunsan/testing/setenv.hpp>

#include <cstdlib>

BOOST_AUTO_TEST_SUITE(testing)

BOOST_AUTO_TEST_CASE(env)
{
    const char var[] = "unknown_environment_variable";
    const char value[] = "value";
    BOOST_REQUIRE(!std::getenv(var));
    BOOST_CHECK_EQUAL(bunsan::testing::setenv(var, value, true), 0);
    BOOST_CHECK_EQUAL(bunsan::testing::getenv(var), value);
    BOOST_CHECK_EQUAL(bunsan::testing::unsetenv(var), 0);
    BOOST_CHECK(!std::getenv(var));
}

BOOST_AUTO_TEST_SUITE_END() // testing
