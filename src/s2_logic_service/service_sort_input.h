//
// Created by yanxuewei on 2021/8/7.
//

#ifndef TDD_DEMO_SERVICE_SORT_INPUT_H
#define TDD_DEMO_SERVICE_SORT_INPUT_H

#include "s1_comm/comm.h"

class ServiceSortInput {

public:
    ServiceSortInput();
    
    virtual ~ServiceSortInput();
    
    void sort_input_numbers(__attribute__((unused)) int argc, __attribute__((unused)) char *argv[]);
    
    void PleaseInputNumbers(std::vector<std::string> &input_str_nums_vector);
    
    static void ConvertTo(const std::string &src, std::vector<std::string> &dst_vector,
                          const std::string &pattern = " ,|;");
    
    static void ConvertTo(const std::vector<std::string> &src_vector,
                          std::vector<int> &dst_vector);
    
    static void Output(const std::vector<int> &ret_nums_vector);
    
    static bool IsQuit();
};


#endif //TDD_DEMO_SERVICE_SORT_INPUT_H