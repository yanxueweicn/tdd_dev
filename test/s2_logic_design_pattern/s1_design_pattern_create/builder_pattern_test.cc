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
  // LenovoBuilder
  std::unique_ptr<Builder> builder(new LenovoBuilder());
  EXPECT_STREQ(builder->to_string().c_str(),
               "LenovoBuilder{make_order_desc=|computer={cpu=,memory=,hard_disk=,display=,keyboard=}}");
  Director director(*builder);
  Computer *computer_ptr = director.Construct();
  if (computer_ptr)
    ComputerSetup(*computer_ptr);
  EXPECT_STREQ(builder->to_string().c_str(),
               "LenovoBuilder{make_order_desc=cpu->memory->hard_disk->keyboard->display|computer={cpu=Intel,memory=Samsung,hard_disk=WesternData,display=Samsung,keyboard=Lenovo}}");


  // DellBuilder
  builder.reset(new DellBuilder());
  Director director2(*builder);
  computer_ptr = director2.ConstructStrong();
  if (computer_ptr)
    ComputerSetup(*computer_ptr);
  EXPECT_STREQ(builder->to_string().c_str(),
               "DellBuilder{make_order_desc=2cpu->memory->2hard_disk->2display->keyboard|computer={cpu=Amd,memory=Kingston,hard_disk=Seagate,display=Philips,keyboard=Logitech}}");
}