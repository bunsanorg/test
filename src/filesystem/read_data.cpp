#include "bunsan/testing/filesystem/read_data.hpp"

#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/test/unit_test.hpp>

namespace bunsan{namespace testing{namespace filesystem
{
    std::string read_data(const boost::filesystem::path &path)
    {
        BOOST_TEST_CHECKPOINT(BOOST_CURRENT_FUNCTION);
        BOOST_TEST_MESSAGE("Attempt to read " << path << ".");
        BOOST_REQUIRE(boost::filesystem::exists(path));
        boost::filesystem::ifstream fin(path);
        BOOST_REQUIRE(fin.is_open());
        const std::string rdata{
            std::istreambuf_iterator<char>(fin),
            std::istreambuf_iterator<char>()
        };
        BOOST_REQUIRE(fin);
        fin.close();
        BOOST_REQUIRE(fin);
        return rdata;
    }
}}}
