#pragma once

namespace bunsan{namespace testing
{
    int setenv(const char *const key, const char *const value, const bool overwrite);
    int unsetenv(const char *const key);
}}
