project(bunsan_testing)

include(${CMAKE_SOURCE_DIR}/system-config.cmake OPTIONAL)

cmake_minimum_required(VERSION 2.8)

include(BunsanCommon)

# BOOST
bunsan_use_boost(system filesystem unit_test_framework)
add_definitions(-DBOOST_TEST_DYN_LINK)

bunsan_add_shared_library(${PROJECT_NAME}
    src/getenv.cpp
    src/setenv.cpp
    src/environment.cpp

    src/filesystem/tempdir.cpp
    src/filesystem/tempfiles.cpp
    src/filesystem/tempfile.cpp
    src/filesystem/read_data.cpp
    src/filesystem/write_data.cpp
)

bunsan_install_headers()
bunsan_install_targets(${PROJECT_NAME})
bunsan_install_plugins(BunsanCmake)

bunsan_include_tests()
