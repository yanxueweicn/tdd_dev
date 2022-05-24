//
// Created by fanyan on 2021/9/28.
//
#include "comm.h"

TestClass::TestClass(const string &name, int age, string &nameAlias,
                     const bool sex) : name_(name), age_(age),
                                       name_alias_(nameAlias), sex_(sex) {}

TestClass::TestClass(const string &name, int age) : name_(name), age_(age),
                                                    name_alias_(const_cast<string &>(name)), sex_(-1) {}