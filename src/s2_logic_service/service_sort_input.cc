//
// Created by yanxuewei on 2021/8/7.
//

#include <algorithm>
#include "service_sort_input.h"


ServiceSortInput::ServiceSortInput() = default;

ServiceSortInput::~ServiceSortInput() = default;


void ServiceSortInput::sort_input_numbers(__attribute__((unused)) int argc, __attribute__((unused)) char **argv) {
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
    std::cout << "Do you want to quit(Y/n)?";
    std::cin >> is_quit;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return (is_quit == 'Y' || is_quit == 'y');
}

static bool is_find(const string &src_str, const string &delimiter_str, size_t &index) {
    bool is_have = false;
    do {
        if (src_str.empty() || delimiter_str.empty()) break;
        
        size_t size = 10;
        if (size > delimiter_str.size()) size = delimiter_str.size();
        
        for (int i = 0; i < size; ++i) {
            index = src_str.find(delimiter_str[i], 0);
            
            if (index != string::npos) {
                is_have = true;
                break;
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
    
        size_t index = -1;
        size_t start_index = 0;
        string src(src_str);
        while (is_find(src, pattern, index)) {
            ret.push_back(src.substr(start_index, (index - start_index)));
            src = src.substr(index + 1, src.size() - index - 1);
        }
    
        if (index == -1) ret.push_back(src);
    
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
    std::cout << "sorted result: ";
    for (auto &one: ret_nums_vector) {
        std::cout << one << " ";
    }
    std::cout << std::endl;
}