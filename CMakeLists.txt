project(bunsan_testing)

include(${CMAKE_SOURCE_DIR}/system-config.cmake OPTIONAL)

cmake_minimum_required(VERSION 3.0)

find_package(BunsanCMake CONFIG REQUIRED)

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
target_compile_definitions(${PROJECT_NAME} PUBLIC BOOST_TEST_DYN_LINK)
bunsan_use_package(${PROJECT_NAME} Boost
    system
    filesystem
    unit_test_framework
)

bunsan_install_headers()
bunsan_install_targets(${PROJECT_NAME})
bunsan_install_project()

bunsan_include_tests()
