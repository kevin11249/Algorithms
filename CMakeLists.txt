cmake_minimum_required(VERSION 3.5)

project(Algorithms)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)


# Unit tests
enable_testing()

add_executable(algorithms_unit_tests unit_tests.cpp)

target_link_libraries(algorithms_unit_tests
    Boost::unit_test_framework
)

target_compile_definitions(algorithms_unit_tests
    PRIVATE
        BOOST_TEST_DYN_LINK
)

add_test(test_all algorithms_unit_tests)