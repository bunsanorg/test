#pragma once

#include <boost/filesystem/path.hpp>

namespace bunsan{namespace testing{namespace filesystem
{
    std::string read_data(const boost::filesystem::path &path);
}}}
