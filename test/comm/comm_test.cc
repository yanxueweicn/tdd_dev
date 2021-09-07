//
// Created by yanxuewei on 2021/8/7.
//

#include "comm/comm.h"

#include "gtest/gtest.h"

TEST(DisplayBegin, IsNotEmpty) {
    std::string ret = display_begin();
    EXPECT_FALSE(ret.empty());
}

TEST(DisplayEnd, IsNotEmpty) {
    std::string ret = display_end();
    EXPECT_FALSE(ret.empty());
}