#pragma once

namespace bunsan{namespace test
{
    int setenv(const char *const key,
               const char *const value,
               const bool overwrite);
    int unsetenv(const char *const key);
}}

#define BUNSAN_TEST_SETOPT(NAME, VALUE) \
    const static int NAME##_##__LINE__ = \
        ::bunsan::test::setenv(#NAME, VALUE, true)
