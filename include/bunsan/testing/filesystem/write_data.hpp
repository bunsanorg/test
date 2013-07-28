#pragma once

#include <boost/filesystem/path.hpp>

namespace bunsan{namespace testing{namespace filesystem
{
    void write_data(const boost::filesystem::path &path, const std::string &data);
}}}
