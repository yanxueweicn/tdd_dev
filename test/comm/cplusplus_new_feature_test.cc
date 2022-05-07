//
// Created by fanyan on 2022/1/25.
//

#include <bits/stdc++.h>

#include <ctime>
#include <iostream>

#include <gtest/gtest.h>

TEST(NewFeatureCXX11, NormalAuto) {
    std::string ret;
    ret.reserve(256);
    
    // auto ref const voliate lost
    
    // auto support initialization list
    for (const auto &i: {1, 2, 3, 4})
        ret.append(std::to_string(i)).append(" ");
    EXPECT_STREQ(ret.c_str(), "1 2 3 4 ");
}

static void DemoProcessRun() {
    std::cout << "Start Run... " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "End Run. " << std::endl;
}

/**
 *
 * 使用代码来测试时间
 *
 */
TEST(CostTime, ComputeTime) {
    // 1. clock
    clock_t start = clock();
    DemoProcessRun();
    double cost_time_ms = (clock() - start) / CLOCKS_PER_SEC;
    std::cout << "===^^ 测试程序:" << cost_time_ms << "(start:" << start << ")" << std::endl;
    // 2.gettimeofday
    // 3. throno time
}

/**
 *
 *
 *
 *
 *
*/
TEST(CStringFunc, memchr) {
    // memchr
    // memmove
    // memcpy
    // memset
    // memcmp
    
    // strncat
    // strcat
    // strcpy
    // strncpy
    // strncmp
    // strcmp
    // strcoll
    
    // strlen
    // strchr
    // strrchr
    // strcspn
    // strspn
    // strstr
    // strpbrk
    
    // strtok
    // strxfrm
    // strerror
    //
    
}