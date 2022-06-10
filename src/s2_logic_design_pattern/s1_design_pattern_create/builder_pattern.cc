//
// Created by yanxuewei on 2022/6/3.
//

#include "builder_pattern.h"
#include <iostream>

void Computer::InitSetup() { std::cout << "Computer InitSetup!!!\n"; }

void Computer::SetupGame() { std::cout << "Computer SetupGame!!!\n"; }

void Computer::GameStart() { std::cout << "Computer GameStart!!!\n"; }
const std::unique_ptr<Cpu> &Computer::GetCpu() const {
  return cpu_;
}
void Computer::SetCpu(std::unique_ptr<Cpu> &cpu) {
  cpu_ = std::move(cpu);
}

const std::unique_ptr<Memory> &Computer::GetMemory() const {
  return memory_;
}
void Computer::SetMemory(std::unique_ptr<Memory> &memory) {
  memory_ = std::move(memory);
}
const std::unique_ptr<HardDisk> &Computer::GetHardDisk() const {
  return hard_disk_;
}
void Computer::SetHardDisk(std::unique_ptr<HardDisk> &hard_disk) {
  hard_disk_ = std::move(hard_disk);
}
const std::unique_ptr<Display> &Computer::GetDisplay() const {
  return display_;
}
void Computer::SetDisplay(std::unique_ptr<Display> &display) {
  display_ = std::move(display);
}
const std::unique_ptr<Keyboard> &Computer::GetKeyboard() const {
  return keyboard_;
}
void Computer::SetKeyboard(std::unique_ptr<Keyboard> &keyboard) {
  keyboard_ = std::move(keyboard);
}

std::string Computer::to_string() {
  std::string ret;
  ret.reserve(128);

  ret.append("computer={");
  ret.append("cpu=").append(cpu_ ? cpu_->to_string() : "");
  ret.append(",memory=").append(memory_ ? memory_->to_string() : "");
  ret.append(",hard_disk=").append(hard_disk_ ? hard_disk_->to_string() : "");
  ret.append(",display=").append(display_ ? display_->to_string() : "");
  ret.append(",keyboard=").append(keyboard_ ? keyboard_->to_string() : "");
  ret.append("}");

  return ret;
}

void Builder::MakeCpu() {
  std::cout << "***MakeCpu() must be override\n";
}

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

Computer *Builder::GetResult() { return nullptr; }

std::string Builder::to_string() { return "unknown implementation"; }

void Builder::MakeOrderDesc(const std::string &desc) {}

Director::Director(const Builder &builder)
    : builder_(const_cast<Builder &>(builder)) {}

Computer *Director::Construct() {
  // 可以按照自己的顺序来建造
  // cpu->memory->hard_disk->keyboard->display
  builder_.MakeOrderDesc("cpu->memory->hard_disk->keyboard->display");

  builder_.MakeCpu();
  builder_.MakeMemory();
  builder_.MakeHardDisk();
  builder_.MakeKeyboard();
  builder_.MakeDisplay();
  return builder_.GetResult();
}

Computer *Director::ConstructStrong() {
  // 可以按照自己的顺序来建造
  // 2cpu->memory->2hard_disk->2display->keyboard
  builder_.MakeOrderDesc("2cpu->memory->2hard_disk->2display->keyboard");

  builder_.MakeCpu();
  builder_.MakeCpu();
  builder_.MakeMemory();
  builder_.MakeHardDisk();
  builder_.MakeHardDisk();
  builder_.MakeDisplay();
  builder_.MakeDisplay();
  builder_.MakeKeyboard();
  return builder_.GetResult();
}

LenovoBuilder::LenovoBuilder()
    : cpu_(new Intel()), memory_(new Samsung()),
      hard_disk_(new WesternDatabase()), display_(new Samsung()),
      keyboard_(new Lenovo()) {}

void LenovoBuilder::MakeCpu() {
  computer_.SetCpu(cpu_);
  std::cout << "MakeCpu ";
}

void LenovoBuilder::MakeMemory() {
  computer_.SetMemory(memory_);
  std::cout << "MakeMemory ";
}

void LenovoBuilder::MakeHardDisk() {
  computer_.SetHardDisk(hard_disk_);
  std::cout << "MakeHardDisk ";
}

void LenovoBuilder::MakeDisplay() {
  computer_.SetDisplay(display_);
  std::cout << "MakeDisplay ";
}

void LenovoBuilder::MakeKeyboard() {
  computer_.SetKeyboard(keyboard_);
  std::cout << "MakeKeyboard ";
}

Computer *LenovoBuilder::GetResult() { return &computer_; }

void LenovoBuilder::MakeOrderDesc(const std::string &desc) {
  Builder::MakeOrderDesc(desc);
  make_order_desc_.assign(desc);
}

std::string LenovoBuilder::to_string() {
  std::string ret;
  ret.reserve(128);

  ret.append("LenovoBuilder");
  ret.append("{");

  ret.append("make_order_desc=").append(make_order_desc_);
  ret.append("|").append(computer_.to_string());

  ret.append("}");

  return ret;
}

DellBuilder::DellBuilder()
    : cpu_(new Amd()), memory_(new Kingston()),
      hard_disk_(new Seagate()), display_(new Philips()),
      keyboard_(new Logitech()) {}

void DellBuilder::MakeCpu() {
  computer_.SetCpu(cpu_);
  std::cout << "MakeCpu ";
}

void DellBuilder::MakeMemory() {
  computer_.SetMemory(memory_);
  std::cout << "MakeMemory ";
}

void DellBuilder::MakeHardDisk() {
  computer_.SetHardDisk(hard_disk_);
  std::cout << "MakeHardDisk ";
}

void DellBuilder::MakeDisplay() {
  computer_.SetDisplay(display_);
  std::cout << "MakeDisplay ";
}

void DellBuilder::MakeKeyboard() {
  computer_.SetKeyboard(keyboard_);
  std::cout << "MakeKeyboard ";
}

std::string DellBuilder::to_string() {
  std::string ret;
  ret.reserve(128);

  ret.append("DellBuilder");
  ret.append("{");

  ret.append("make_order_desc=").append(make_order_desc_);
  ret.append("|").append(computer_.to_string());

  ret.append("}");

  return ret;
}

Computer *DellBuilder::GetResult() { return &computer_; }

void DellBuilder::MakeOrderDesc(const std::string &desc) {
  Builder::MakeOrderDesc(desc);
  make_order_desc_.assign(desc);
}

std::string Cpu::to_string() { return "unknown Cpu"; }

std::string Intel::to_string() { return "Intel"; }

std::string Amd::to_string() { return "Amd"; }

std::string Memory::to_string() { return "unknown Memory"; }

std::string Kingston::to_string() { return "Kingston"; }

std::string HardDisk::to_string() { return "unknown HardDisk"; }

std::string WesternDatabase::to_string() { return "WesternData"; }

std::string Seagate::to_string() { return "Seagate"; }

std::string Display::to_string() { return "unknown Display"; }

std::string Samsung::to_string() { return "Samsung"; }

std::string Philips::to_string() { return "Philips"; }

std::string Keyboard::to_string() { return "unknown Keyboard"; }

std::string Lenovo::to_string() { return "Lenovo"; }

std::string Logitech::to_string() { return "Logitech"; }