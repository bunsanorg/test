cmake_minimum_required(VERSION 3.0)

include(${CMAKE_SOURCE_DIR}/system-config.cmake OPTIONAL)

project(bunsan_testing)

find_package(BunsanCMake CONFIG REQUIRED)

bunsan_add_library(${PROJECT_NAME}
    src/getenv.cpp
    src/setenv.cpp
    src/environment.cpp

    src/filesystem/tempdir.cpp
    src/filesystem/tempfiles.cpp
    src/filesystem/tempfile.cpp
    src/filesystem/read_data.cpp
    src/filesystem/write_data.cpp
)
bunsan_use_threads(${PROJECT_NAME})
bunsan_use_boost(${PROJECT_NAME}
    system
    filesystem
    unit_test_framework
)

bunsan_install_headers()
bunsan_install_targets(${PROJECT_NAME})
bunsan_install_project()

bunsan_include_tests()
