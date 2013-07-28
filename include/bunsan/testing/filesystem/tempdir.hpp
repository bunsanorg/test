#pragma once

#include <boost/filesystem/path.hpp>
#include <boost/noncopyable.hpp>

namespace bunsan{namespace testing{namespace filesystem
{
    struct tempdir: private boost::noncopyable
    {
        tempdir();
        ~tempdir();

        boost::filesystem::path path;
    };
}}}
