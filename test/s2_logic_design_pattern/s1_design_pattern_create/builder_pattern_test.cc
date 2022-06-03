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

TEST(BuilderPattern, Normal) {
  std::unique_ptr<Builder> builder(new LenovoBuilder());
  Director director(*builder.get());
  Computer computer = director.Construct();
  ComputerSetup(computer);

  EXPECT_STREQ(builder->to_string().c_str(),
               "LenovoBuilder{cpu=intel,memory=sumsung,hard_disk=western_data,"
               "display=sumsung,keyboard=lenovo}");
}