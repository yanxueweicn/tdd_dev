//
// Created by yanxuewei on 2021/8/7.
//

#include <algorithm>
#include "service_sort_input.h"


ServiceSortInput::ServiceSortInput() {}

ServiceSortInput::~ServiceSortInput() {

}


void ServiceSortInput::sort_input_numbers(int argc, char **argv) {
    do {
        std::vector<std::string> input_str_nums_vector;
        PleaseInputNumbers(input_str_nums_vector);
        
        std::vector<int> ret_nums_vector;
        ConvertTo(input_str_nums_vector, ret_nums_vector);
        
        Output(ret_nums_vector);
        
        if (IsQuit()) break;
    } while (true);
}

void ServiceSortInput::PleaseInputNumbers(std::vector<std::string> &input_str_nums_vector) {
    std::string one_row_string;
    std::cout << std::endl << "Please input some numbers:";
    std::getline(std::cin, one_row_string);
    
    ConvertTo(one_row_string, input_str_nums_vector);
}

bool ServiceSortInput::IsQuit() {
    char is_quit = 'N';
    std::cout << std::endl << "Do you want to quite(Y/n)?";
    is_quit = std::cin.get();
    return (is_quit == 'Y' || is_quit == 'y');
}

static bool is_find(const string &src_str, const string &pattern, int start_index, int &index) {
    bool is_have = false;
    do {
        if (src_str.empty() || pattern.empty()) break;
        
        char opers[10] = {0};
        int size = 10;
        if (size > pattern.size()) size = pattern.size();
        pattern.copy(opers, size, 0);
        
        int temp_index = -1;
        for (int i = 0; i < size; ++i) {
            temp_index = src_str.find(opers[i], start_index);
            
            if (temp_index != string::npos) {
                if (index == -1) index = temp_index;
                else if (index > temp_index) index = temp_index;
                is_have = true;
            }
        }
        
    } while (false);
    return is_have;
}

void ServiceSortInput::ConvertTo(const string &src_str, std::vector<std::string> &ret,
                                 const std::string &pattern) {
    do {
        if (src_str.empty()) break;
        if (!ret.empty()) ret.clear();
        
        if (pattern.empty()) {
            ret.push_back(src_str);
            break;
        }
        
        int index = -1, start_index = 0;
        string src(src_str);
        while (is_find(src, pattern, start_index, index)) {
            ret.push_back(src.substr(start_index, (index - start_index)));
//            ret.push_back(string(1, src[index]));
            src = src.substr(index + 1, src.size() - index - 1);
        }
        
        if (index == -1) ret.push_back(src_str);
        else {
            ret.push_back(src.substr(start_index, src.length() - start_index));
        }
        
        
    } while (false);
    
}

void ServiceSortInput::ConvertTo(const std::vector<std::string> &src_vector, std::vector<int> &dst_vector) {
    if (!dst_vector.empty()) dst_vector.clear();
    for (auto &one: src_vector) {
        try {
            dst_vector.push_back(std::stoi(one));
        } catch (...) {}
    }
    std::sort(dst_vector.begin(), dst_vector.end());
}

void ServiceSortInput::Output(const std::vector<int> &ret_nums_vector) {
    std::cout << std::endl << "sorted result: ";
    for (auto &one: ret_nums_vector) {
        std::cout << one << " ";
    }
    std::cout << std::endl;
}