cmake_minimum_required(VERSION 3.16)
project(tdd_demo)

set(CMAKE_CXX_STANDARD 11)


add_subdirectory(lib/third_ext/googletest)
include_directories(lib/third_ext/googletest/googletest/include)
include_directories(lib/third_ext/googletest/googlemock/include)


include_directories(.)
include_directories(src)


add_executable(tdd_demo
        src/main.cc
        src/service/service_sort_input.cc
        
        test/comm/comm_test.cc
        test/service/service_sort_input_test.cc
        )


target_link_libraries(tdd_demo gtest_main gmock)

#include(GoogleTest)
#gtest_discover_tests(study_c_plus_plus)