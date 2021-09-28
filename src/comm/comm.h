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

class TestClass {
public:
    TestClass(const string &name, int age, string &nameAlias, const bool sex);
    
    TestClass(const string &name, int age);
    
    string ToString(const string &prefix = "") {
        string ret;
        ret.reserve(64);
        
        ret.append("prefix");
        ret.append("{");
        
        ret.append("}");
        
        return ret;
    }

private:
    string name_;
    int age_;
    string &name_alias_;
    const bool sex_;
};


#endif /* TDD_DEMO_SRC_COMM_COMM*/