//
// Created by fanyan on 2022/1/25.
//

#include <bits/stdc++.h>

#include <iostream>

#include <gtest/gtest.h>


TEST(NewFeatureCXX11, NormalAuto) {
    std::string ret;
    ret.reserve(256);
    
    // auto support initialization list
    for (const auto &i: {1, 2, 3, 4})
        ret.append(std::to_string(i)).append(" ");
    EXPECT_STREQ(ret.c_str(), "1 2 3 4 ");
    
    
}