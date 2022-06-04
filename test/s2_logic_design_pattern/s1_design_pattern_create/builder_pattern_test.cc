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
               "LenovoBuilder{make_order_desc=|parts={cpu=Intel,memory=Samsung,hard_disk=WesternData,display=Samsung,keyboard=Lenovo}}");
  Director director(*builder);
  Computer *computer_ptr = director.Construct();
  if (computer_ptr)
    ComputerSetup(*computer_ptr);
  EXPECT_STREQ(builder->to_string().c_str(),
               "LenovoBuilder{make_order_desc=cpu->memory->hard_disk->keyboard->display|parts={cpu=Intel,memory=Samsung,hard_disk=WesternData,display=Samsung,keyboard=Lenovo}}");


  // DellBuilder
//  std::unique_ptr<Builder> builder2(new DellBuilder());
//  Director director2(*builder2);
//  Computer *computer_ptr2 = director2.Construct();
//  if (computer_ptr2)
//    ComputerSetup(*computer_ptr2);
//  EXPECT_STREQ(builder2->to_string().c_str(),
//               "DellBuilder{cpu=Amd,memory=Kingston,hard_disk=Seagate,display=Philips,keyboard=Logitech}");

  builder.reset(new DellBuilder());
  Director director2(*builder);
  Computer *computer_ptr2 = director2.Construct();
  if (computer_ptr2)
    ComputerSetup(*computer_ptr2);
  EXPECT_STREQ(builder->to_string().c_str(),
               "DellBuilder{make_order_desc=cpu->memory->hard_disk->keyboard->display|parts={cpu=Amd,memory=Kingston,hard_disk=Seagate,display=Philips,keyboard=Logitech}}");
}