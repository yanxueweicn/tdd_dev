#include "s3_db/db_tool.h"

#include "gmock/gmock.h"
#include "mock_store_service.h"

using ::testing::AtLeast;
using ::testing::Return;
/*
 * 测试用例如下：
 * input-->output
 *  name --> "name:bob,age:16,sex:male"
 * #. dbTool.add_info("name:bob,age:16,sex:male")-->true
 * #. dbTool.find_info("bob")-->"name:bob,age:16,sex:male
 * */
TEST(DbToolTest, AddInfoIsSucc) {

  string one_info("name:bob,age:16,sex:male");

  MockStoreService store;
  EXPECT_CALL(store, add_one_row(one_info))
      .Times(AtLeast(1))
      .WillOnce(Return(true));

  DbTool dbTool(&store);
  EXPECT_TRUE(dbTool.add_info(one_info));
}

TEST(DbToolTest, FindInfoNormal) {
  std::string name = "bob";
  static const char *const one_row_value = "name:bob,age:16,sex:male";

  MockStoreService store;
  EXPECT_CALL(store, find_one_row_by_key(name))
      .WillOnce(Return(one_row_value));

  DbTool dbTool(&store);
  EXPECT_STREQ(dbTool.find_info(name).c_str(), one_row_value);
}