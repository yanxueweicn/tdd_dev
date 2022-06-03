//

// Created by yanxuewei on 2022/6/3.

//

#include "builder_pattern.h"
#include <iostream>

void Computer::InitSetup() { std::cout << "Computer InitSetup!!!\n"; }

void Computer::SetupGame() { std::cout << "Computer SetupGame!!!\n"; }

void Computer::GameStart() { std::cout << "Computer GameStart!!!\n"; }

void Builder::MakeCpu() { std::cout << "***MakeCpu() must be override\n"; }

void Builder::MakeMemory() {
  std::cout << "*** MakeMemory() must be override ***\n";
}

void Builder::MakeHardDisk() {
  std::cout << "*** MakeHardDisk() must be override ***\n";
}

void Builder::MakeDisplay() {
  std::cout << "*** MakeDisplay() must be override ***\n";
}

void Builder::MakeKeyboard() {
  std::cout << "*** MakeKeyboard() must be override ***\n";
}

std::string Builder::to_string() { return ""; }

Computer Builder::GetResult() { return Computer(); }

void LenovoBuilder::MakeCpu() {}

void LenovoBuilder::MakeHardDisk() {}

void LenovoBuilder::MakeDisplay() {}

void LenovoBuilder::MakeKeyboard() {}

std::string LenovoBuilder::to_string() {
  std::string ret;

  return ret;
}

Computer LenovoBuilder::GetResult() {}

Director::Director(const Builder &builder) {}
Computer Director::Construct() { return Computer(); }
void DellBuilder::MakeCpu() {}

void DellBuilder::MakeMemory() {}

void DellBuilder::MakeHardDisk() {}

void DellBuilder::MakeDisplay() {}

void DellBuilder::MakeKeyboard() {}

std::string DellBuilder::to_string() {}

Computer DellBuilder::GetResult() {}
