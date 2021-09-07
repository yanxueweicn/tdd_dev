#ifndef TDD_DEMO_SRC_COMM_COMM_H
#define TDD_DEMO_SRC_COMM_COMM_H

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;

inline std::string display_begin() {
    std::string ret;
    ret.append("Game Start!!!!");
    return ret;
}

inline std::string display_end() {
    std::string ret;
    ret.append("Game End!!!!");
    return ret;
}


#endif /* TDD_DEMO_SRC_COMM_COMM*/