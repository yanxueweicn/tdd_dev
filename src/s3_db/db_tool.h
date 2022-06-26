//
// Created by fanyan on 2021-7-7.
//

#ifndef TDD_DEMO_DB_TOOL_H
#define TDD_DEMO_DB_TOOL_H

#include <iostream>
#include <sstream>
#include <string>

#include "store_service.h"

using std::cout;
using std::endl;
using std::string;

class DbTool {

 public:
  explicit DbTool(StoreService *store);

  virtual ~DbTool();

  bool add_info(const std::string &info);

  string find_info(const string &name);

 private:
  StoreService *store_ptr_;
};

#endif //TDD_DEMO_DB_TOOL_H
