//
// Created by yanxuewei on 2021/8/7.
//

#include "comm/comm.h"

#include "gtest/gtest.h"

TEST(DisplayBegin, IsNotEmpty) {
    
    std::string ret = display_begin();
    EXPECT_FALSE(ret.empty());
    
    
}

//TEST(DisplayEnd, IsNotEmpty) {
//    std::string ret = display_end();
//    EXPECT_FALSE(ret.empty());
//}
TEST(TestClass, RefAndConstField) {
    // test ref is not transfer
    int a = 2;
    int &b = a;
    EXPECT_EQ(b, a);
    
    int c = 5;
    b = c;
    EXPECT_EQ(b, c);
    EXPECT_EQ(a, b);
    EXPECT_EQ(a, 5);
    
    ++b;
    EXPECT_EQ(b, 6);
    EXPECT_EQ(c, 5);
    
    // test const field and ref field can't use default constructor&assignment method
    TestClass test_one("fanyan", 42);
    TestClass test_two("yxw", 24);
    TestClass test_three(test_one);
    
    test_two = test_one;
    EXPECT_STREQ(test_one.ToString().c_str(), "{name='fanyan',age=42}");
    
}