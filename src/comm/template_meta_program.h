//
// Created by yanxuewei on 2022/1/10.
//

#ifndef TDD_DEMO_TEMPLATE_META_PROGRAM_H
#define TDD_DEMO_TEMPLATE_META_PROGRAM_H

#include <type_traits>

template<typename T, T value, template<typename> class A, typename... Args>
class TmpDemo {

};

std::string TmpDemoFunction() {
    return "";
}

template<typename T, typename... Args, typename std::enable_if<std::is_arithmetic<T>::value, T *>::type= nullptr>
std::string TmpDemoFunction(T first, Args... others) {
    std::string ret;
    ret.append(std::to_string(first));
    ret.append(TmpDemoFunction(others...));
    return ret;
}

template<typename T, typename... Args, typename std::enable_if<!std::is_arithmetic<T>::value, T *>::type= nullptr>
std::string TmpDemoFunction(T first, Args... others) {
    std::string ret;
    ret.append(first);
    ret.append(TmpDemoFunction(others...));
    return ret;
}


#endif //TDD_DEMO_TEMPLATE_META_PROGRAM_H
