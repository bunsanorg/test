#include <bunsan/test/filesystem/tempfile.hpp>

namespace bunsan{namespace test{namespace filesystem
{
    tempfile::tempfile(): path(allocate()) {}
}}}
