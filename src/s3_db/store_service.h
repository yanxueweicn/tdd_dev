
#ifndef TDD_DEMO_STORE_SERVICE_H
#define TDD_DEMO_STORE_SERVICE_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class StoreService {
 public:
  virtual void display() = 0;

  virtual bool add_one_row(const std::string &one_row_info);

  virtual string find_one_row_by_key(const string &key);
};

#endif //TDD_DEMO_STORE_SERVICE_H