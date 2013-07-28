#include "bunsan/testing/setenv.hpp"

#include <cstdlib>

namespace bunsan{namespace testing
{
    int setenv(const char *const key, const char *const value, const bool overwrite)
    {
        return ::setenv(key, value, static_cast<int>(overwrite));
    }

    int unsetenv(const char *const key)
    {
        return ::unsetenv(key);
    }
}}
