#define BOOST_TEST_MODULE filesystem
#include <boost/test/unit_test.hpp>

#include "bunsan/testing/filesystem/tempfiles.hpp"
#include "bunsan/testing/filesystem/tempfile.hpp"
#include "bunsan/testing/filesystem/tempdir.hpp"
#include "bunsan/testing/filesystem/read_data.hpp"
#include "bunsan/testing/filesystem/write_data.hpp"

#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/operations.hpp>

BOOST_AUTO_TEST_SUITE(testing)

BOOST_AUTO_TEST_SUITE(filesystem)

BOOST_AUTO_TEST_CASE(tempfiles)
{
    boost::filesystem::path path1, path2;
    {
        bunsan::testing::filesystem::tempfiles tmp;
        path1 = tmp.allocate();
        path2 = tmp.allocate();
        BOOST_REQUIRE(boost::filesystem::exists(path1));
        BOOST_REQUIRE(boost::filesystem::exists(path2));
    }
    BOOST_REQUIRE(!boost::filesystem::exists(path1));
    BOOST_REQUIRE(!boost::filesystem::exists(path2));
}

BOOST_AUTO_TEST_CASE(tempfile)
{
    boost::filesystem::path path;
    {
        bunsan::testing::filesystem::tempfile tmp;
        path = tmp.path;
        BOOST_REQUIRE(boost::filesystem::exists(path));
    }
    BOOST_REQUIRE(!boost::filesystem::exists(path));
}

BOOST_AUTO_TEST_CASE(tempdir)
{
    boost::filesystem::path path;
    {
        bunsan::testing::filesystem::tempdir tmp;
        path = tmp.path;
        BOOST_REQUIRE(boost::filesystem::exists(path));
    }
    BOOST_CHECK(!boost::filesystem::exists(path));
    if (boost::filesystem::exists(path))
        BOOST_REQUIRE(boost::filesystem::remove(path));
}

BOOST_FIXTURE_TEST_CASE(read_data, bunsan::testing::filesystem::tempdir)
{
    const boost::filesystem::path file = path / "file";
    const std::string some_data = "Hello, world! I am testing framework.";
    boost::filesystem::ofstream fout(file);
    fout << some_data;
    fout.close();
    BOOST_REQUIRE(boost::filesystem::exists(file));
    BOOST_CHECK_EQUAL(bunsan::testing::filesystem::read_data(file), some_data);
}

BOOST_FIXTURE_TEST_CASE(write_data, bunsan::testing::filesystem::tempdir)
{
    const boost::filesystem::path file = path / "file";
    const std::string some_data = "Hello, world! I am testing framework.";
    bunsan::testing::filesystem::write_data(file, some_data);
    BOOST_CHECK_EQUAL(bunsan::testing::filesystem::read_data(file), some_data);
}

BOOST_AUTO_TEST_SUITE_END() // filesystem

BOOST_AUTO_TEST_SUITE_END() // testing
