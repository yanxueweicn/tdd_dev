//
// Created by yanxuewei on 2021/8/8.
//
#include "gtest/gtest.h"
#include "service/service_sort_input.h"

//TEST(ServiceSortInput, PleaseInputNumbersInputZero) {
//    ServiceSortInput s2_logic_service;
//    std::vector<std::string> input_str_nums_vector;
//    s2_logic_service.PleaseInputNumbers(input_str_nums_vector);
//
//    EXPECT_NE(input_str_nums_vector.size(), 0);
//}

TEST(ServiceSortInput, ConvertToVectorOneNumber) {
    ServiceSortInput service;
    std::vector<std::string> dst_vector;
    std::string src("0");
    service.ConvertTo(src, dst_vector);
    
    EXPECT_NE(dst_vector.size(), 0);
    ASSERT_EQ(dst_vector.size(), 1);
    EXPECT_EQ(dst_vector[0], "0");
    
    src = "1";
    service.ConvertTo(src, dst_vector);
    ASSERT_EQ(dst_vector.size(), 1);
    EXPECT_EQ(dst_vector[0], "1");
}

TEST(ServiceSortInput, ConvertToVectorManyNumbers) {
    ServiceSortInput service;
    std::vector<std::string> dst_vector;
    std::string src("0 1");
    service.ConvertTo(src, dst_vector);
    
    EXPECT_EQ(dst_vector.size(), 2);
    ASSERT_EQ(dst_vector.size(), 2);
    EXPECT_EQ(dst_vector[0], "0");
    EXPECT_EQ(dst_vector[1], "1");
    
    src = "1 2";
    service.ConvertTo(src, dst_vector);
    ASSERT_EQ(dst_vector.size(), 2);
    EXPECT_EQ(dst_vector[0], "1");
    EXPECT_EQ(dst_vector[1], "2");
}

TEST(ServiceSortInput, ConvertToNumberVectorNormal) {
    ServiceSortInput service;
    std::vector<std::string> src_vector{"0", "1"};
    std::vector<int> dst_vector;
    service.ConvertTo(src_vector, dst_vector);
    
    EXPECT_EQ(dst_vector.size(), 2);
    ASSERT_EQ(dst_vector.size(), 2);
    EXPECT_EQ(dst_vector[0], 0);
    EXPECT_EQ(dst_vector[1], 1);
    
    src_vector = {"1", "0"};
    service.ConvertTo(src_vector, dst_vector);
    EXPECT_EQ(dst_vector.size(), 2);
    ASSERT_EQ(dst_vector.size(), 2);
    EXPECT_EQ(dst_vector[0], 0);
    EXPECT_EQ(dst_vector[1], 1);
    
    src_vector = {"1", "0", "2", "5"};
    service.ConvertTo(src_vector, dst_vector);
    EXPECT_EQ(dst_vector.size(), 4);
    ASSERT_EQ(dst_vector.size(), 4);
    EXPECT_EQ(dst_vector[0], 0);
    EXPECT_EQ(dst_vector[1], 1);
    EXPECT_EQ(dst_vector[2], 2);
    EXPECT_EQ(dst_vector[3], 5);
    
}