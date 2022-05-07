cmake_minimum_required(VERSION 3.16)
project(tdd_dev)

set(CMAKE_CXX_STANDARD 11)


add_subdirectory(lib/third_ext/googletest)
include_directories(lib/third_ext/googletest/googletest/include)
include_directories(lib/third_ext/googletest/googlemock/include)


include_directories(.)
include_directories(src)
include_directories(test)


add_executable(tdd_dev
        src/main.cc
        src/comm/comm.cc
        src/comm/simple_object_pool.h
        src/comm/template_meta_program.h
        src/service/service_sort_input.cc
        ####
        #test/comm/comm_test.cc
        test/comm/cplusplus_new_feature_test.cc
        #test/service/service_sort_input_test.cc
        test/prime_tables.h
        #test/sample6_unittest.cc
        #test/sample7_unittest.cc
        #test/sample8_unittest.cc
        test/sample9_unittest.cc
        #test/sample10_unittest.cc
        )


target_link_libraries(tdd_dev gtest_main gmock)

#include(GoogleTest)
#gtest_discover_tests(study_c_plus_plus)