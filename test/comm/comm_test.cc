//
// Created by yanxuewei on 2021/8/7.
//

#include "comm/comm.h"

#include "gtest/gtest.h"

TEST(display_begin, is_not_empty) {
    std::string ret = display_begin();
    EXPECT_FALSE(ret.empty());
}

TEST(display_end, is_not_empty) {
    std::string ret = display_end();
    EXPECT_FALSE(ret.empty());
}