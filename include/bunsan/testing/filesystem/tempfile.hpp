#pragma once

#include <bunsan/testing/filesystem/tempfiles.hpp>

namespace bunsan{namespace testing{namespace filesystem
{
    struct tempfile: private tempfiles
    {
        tempfile();

        boost::filesystem::path path;
    };
}}}
