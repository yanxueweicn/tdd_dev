//
// Created by yanxuewei on 2021/8/7.
//

#ifndef TDD_DEMO_SERVICE_SORT_INPUT_H
#define TDD_DEMO_SERVICE_SORT_INPUT_H

#include "comm/comm.h"

class ServiceSortInput {

public:
    ServiceSortInput();
    
    virtual ~ServiceSortInput();
    
    void sort_input_numbers(int argc, char *argv[]);
    
    void PleaseInputNumbers(std::vector<std::string> &input_str_nums_vector);
    
    void ConvertTo(const std::string &src, std::vector<std::string> &dst_vector,
                   const std::string &pattern = " ");
    
    void ConvertTo(const std::vector<std::string> &src_vector,
                   std::vector<int> &dst_vector);
    
    void Output(const std::vector<int> &ret_nums_vector);
    
    bool IsQuit();
};


#endif //TDD_DEMO_SERVICE_SORT_INPUT_H
