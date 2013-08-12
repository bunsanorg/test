#include <bunsan/testing/environment.hpp>
#include <bunsan/testing/getenv.hpp>

namespace bunsan{namespace testing{namespace dir
{
#define BUNSAN_STATIC_PATH(NAME, EXPR) \
    const boost::filesystem::path &NAME() \
    { \
        static const boost::filesystem::path path = EXPR; \
        return path; \
    }

    BUNSAN_STATIC_PATH(source, getenv("BUNSAN_SOURCE_DIR"))
    BUNSAN_STATIC_PATH(binary, getenv("BUNSAN_BINARY_DIR"))

    namespace tests
    {
        BUNSAN_STATIC_PATH(source, dir::source() / "tests")
        BUNSAN_STATIC_PATH(binary, dir::binary() / "tests");

        namespace resources
        {
            BUNSAN_STATIC_PATH(source, tests::source() / "resources");
            BUNSAN_STATIC_PATH(binary, tests::binary() / "resources");
        }
    }
}}}
