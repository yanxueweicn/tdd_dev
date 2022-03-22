#include <iostream>
#include "comm/comm.h"
#include "service/service_sort_input.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[]) {
    cout << display_begin() << endl;
    //
    ServiceSortInput service_sort_input;
//    service_sort_input.sort_input_numbers(argc, argv);
    
    cout << display_end() << endl;
    
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    
    return 0;
}