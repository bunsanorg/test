project(bunsan_testing)

include(${CMAKE_SOURCE_DIR}/system-config.cmake OPTIONAL)

cmake_minimum_required(VERSION 2.8)

include(BunsanCommon)

# BOOST
bunsan_use_boost(system filesystem unit_test_framework)
add_definitions(-DBOOST_TEST_DYN_LINK)

bunsan_add_shared_library(${PROJECT_NAME}
    src/getenv.cpp
)

bunsan_install_headers()
bunsan_install_targets(${PROJECT_NAME})

bunsan_include_tests()
