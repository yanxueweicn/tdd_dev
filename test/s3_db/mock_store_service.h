//
// Created by fanyan on 2021-7-7.
//
#ifndef TDD_DEMO_TEST_MOCK_STORE_SERVER_H
#define TDD_DEMO_TEST_MOCK_STORE_SERVER_H

#include <iostream>
#include <string>

#include "gmock/gmock.h"

#include "s3_db/store_service.h"

class MockStoreService : public StoreService {
 public:
  MOCK_METHOD(void, display, (), (override));
  MOCK_METHOD(bool, add_one_row, (const std::string& one_row_info), (override));
  MOCK_METHOD(std::string, find_one_row_by_key, (const std::string& key), (override));
};

#endif //TDD_DEMO_TEST_MOCK_STORE_SERVER_H
