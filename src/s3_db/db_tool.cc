
#include "db_tool.h"

DbTool::DbTool(StoreService *store) : store_ptr_(store) {}

DbTool::~DbTool() = default;

bool DbTool::add_info(const string &info) {
  cout << endl;
  cout << "Start add_info....";
  cout << endl;

  bool ret = false;
  do {

    ret = store_ptr_->add_one_row(info);

  } while (false);

  cout << "Invoke end!";
  cout << endl << endl;
  return ret;
}

string DbTool::find_info(const string &name) {
  std::string ret;
  do {
    if (name.empty()) break;
    ret = store_ptr_->find_one_row_by_key(name);
  } while (false);
  return ret;
}