#pragma once

#include <boost/filesystem/path.hpp>
#include <boost/noncopyable.hpp>

namespace bunsan{namespace testing{namespace filesystem
{
    class tempfiles: private boost::noncopyable
    {
    public:
        tempfiles();
        ~tempfiles();

        boost::filesystem::path allocate();

    private:
        std::vector<boost::filesystem::path> m_files;
    };
}}}
