#pragma once

#include <boost/filesystem/path.hpp>

namespace bunsan{namespace testing{namespace filesystem
{
    class tempfiles
    {
    public:
        tempfiles();
        ~tempfiles();

        boost::filesystem::path allocate();

    private:
        std::vector<boost::filesystem::path> m_files;
    };
}}}
