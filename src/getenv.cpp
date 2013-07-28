#include "bunsan/testing/getenv.hpp"

#include <boost/test/unit_test.hpp>

namespace bunsan{namespace testing
{
    const char *getenv(const char *const key)
    {
        BOOST_REQUIRE(key);
        const char *value = ::getenv(key);
        BOOST_REQUIRE(value);
        return value;
    }
}}
