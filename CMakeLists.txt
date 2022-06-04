cmake_minimum_required(VERSION 3.15)
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
        src/s1_comm/comm.cc
        src/s1_comm/simple_object_pool.h
        src/s1_comm/template_meta_program.h
        src/s2_logic_service/service_sort_input.cc
        src/s2_logic_design_pattern/s1_design_pattern_create/builder_pattern.h
        src/s2_logic_design_pattern/s1_design_pattern_create/builder_pattern.cc
        ####
        #test/s1_comm/comm_test.cc
        #test/s1_comm/cplusplus_new_feature_test.cc
        #test/s2_logic_service/service_sort_input_test.cc
        #test/prime_tables.h
        #test/sample6_unittest.cc
        #test/sample7_unittest.cc
        #test/sample8_unittest.cc
        #test/sample9_unittest.cc
        #test/sample10_unittest.cc
        test/s2_logic_design_pattern/s1_design_pattern_create/builder_pattern_test.cc
        )


target_link_libraries(tdd_dev gtest_main gmock)

#include(GoogleTest)
#gtest_discover_tests(study_c_plus_plus)