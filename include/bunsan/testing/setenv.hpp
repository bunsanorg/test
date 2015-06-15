#pragma once

namespace bunsan{namespace testing
{
    int setenv(const char *const key,
               const char *const value,
               const bool overwrite);
    int unsetenv(const char *const key);
}}

#define BUNSAN_TESTING_SETOPT(NAME, VALUE) \
    const static int NAME##_##__LINE__ = \
        ::bunsan::testing::setenv(#NAME, VALUE, true)
