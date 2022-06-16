//
// Created by yanxuewei on 2022/6/3.
//

#include "src/s2_logic_design_pattern/s1_design_pattern_create/builder_pattern.h"
#include "gtest/gtest.h"

namespace {
void ComputerSetup(Computer &computer) {
  computer.InitSetup();
  computer.SetupGame();
  computer.GameStart();
}
} // namespace
TEST(ToStringComputer, Normal) {
  Computer computer;
  EXPECT_STREQ(computer.to_string().c_str(),
               "computer={cpu=,memory=,hard_disk=,display=,keyboard=}");
  EXPECT_STREQ(to_string(computer).c_str(),
               "computer={cpu=,memory=,hard_disk=,display=,keyboard=}");
}
TEST(ToStringUniquePtr, Normal) {
  std::string src = to_string(std::unique_ptr<Cpu>(new Intel()));
  EXPECT_STREQ(src.c_str(), "Intel");
}

TEST(ToStringVectorUniquePtr, Normal) {
  std::vector<std::unique_ptr<Cpu>> src_vec;
  src_vec.push_back(std::unique_ptr<Cpu>(new Intel()));
  src_vec.push_back(std::unique_ptr<Cpu>(new Amd()));
  std::string src = to_string<Cpu>(src_vec);
  EXPECT_STREQ(src.c_str(), "Intel_Amd");

  std::vector<int> src_one = {1, 2, 3};
  std::string ret = to_string<int, std::vector<int> >(src_one);
  EXPECT_STREQ(ret.c_str(), "1_2_3");

  std::string ret2 = to_string<int>(src_one);
  EXPECT_STREQ(ret2.c_str(), "1_2_31");

}

TEST(BuilderPattern, Normal) {

  // LenovoBuilder
  std::unique_ptr<Builder> builder(new LenovoBuilder());
  EXPECT_STREQ(builder->to_string().c_str(),
               "LenovoBuilder{make_order_desc="
               "|computer={cpu=,memory=,hard_disk=,display=,keyboard=}}");
  Director director(*builder);
  Computer *computer_ptr = director.Construct();
  ASSERT_TRUE(computer_ptr != nullptr);

  ComputerSetup(*computer_ptr);
  EXPECT_STREQ(computer_ptr->to_string().c_str(),
               "computer={cpu=Intel,memory=Samsung,hard_disk=WesternData,display=Samsung,keyboard=Lenovo}");
  EXPECT_STREQ(builder->to_string().c_str(),
               "LenovoBuilder{make_order_desc=cpu->memory->hard_disk->keyboard->display"
               "|computer={cpu=Intel,memory=Samsung,hard_disk=WesternData,display=Samsung,keyboard=Lenovo}}");


  // DellBuilder
  builder.reset(new DellBuilder());
  Director director2(*builder);
  computer_ptr = director2.ConstructStrong();
  ASSERT_TRUE(computer_ptr != nullptr);

  ComputerSetup(*computer_ptr);
  EXPECT_STREQ(computer_ptr->to_string().c_str(),
               "computer={cpu=Amd_Amd,memory=Kingston,hard_disk=Seagate_Seagate,display=Philips_Philips,keyboard=Logitech}");
  EXPECT_STREQ(builder->to_string().c_str(),
               "DellBuilder{make_order_desc=2cpu->memory->2hard_disk->2display->keyboard"
               "|computer={cpu=Amd_Amd,memory=Kingston,hard_disk=Seagate_Seagate,display=Philips_Philips,keyboard=Logitech}}");
}