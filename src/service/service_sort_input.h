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
};


#endif //TDD_DEMO_SERVICE_SORT_INPUT_H
