#include "bunsan/testing/filesystem/tempfile.hpp"

namespace bunsan{namespace testing{namespace filesystem
{
    tempfile::tempfile(): path(allocate()) {}
}}}
