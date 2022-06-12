//
// Created by yanxuewei on 2022/6/3.
//

#include "builder_pattern.h"
#include <iostream>

void Computer::InitSetup() { std::cout << "Computer InitSetup!!!\n"; }
void Computer::SetupGame() { std::cout << "Computer SetupGame!!!\n"; }
void Computer::GameStart() { std::cout << "Computer GameStart!!!\n"; }
std::string Computer::to_string() const {
  std::string ret;
  ret.reserve(128);

  ret.append("computer={");
  ret.append("cpu=").append(::to_string < Cpu > (cpu_vec_));
  ret.append(",memory=").append(::to_string < Memory > (memory_vec_));
  ret.append(",hard_disk=").append(::to_string < HardDisk > (hard_disk_vec_));
  ret.append(",display=").append(::to_string < Display > (display_vec_));
  ret.append(",keyboard=").append(::to_string < Keyboard > (keyboard_vec_));
  ret.append("}");

  return ret;
}
const std::vector<std::unique_ptr<Cpu>> &Computer::GetCpuVec() const {
  return cpu_vec_;
}
void Computer::SetCpuVec(std::unique_ptr<Cpu> &cpu_ptr) {
  cpu_vec_.push_back(std::move(cpu_ptr));
}

const std::vector<std::unique_ptr<Memory>> &Computer::GetMemoryVec() const {
  return memory_vec_;
}
void Computer::SetMemoryVec(std::unique_ptr<Memory> &memory_ptr) {
  memory_vec_.push_back(std::move(memory_ptr));
}

const std::vector<std::unique_ptr<HardDisk>> &Computer::GetHardDiskVec() const {
  return hard_disk_vec_;
}
void Computer::SetHardDiskVec(std::unique_ptr<HardDisk> &hard_disk_ptr) {
  hard_disk_vec_.push_back(std::move(hard_disk_ptr));
}

const std::vector<std::unique_ptr<Display>> &Computer::GetDisplayVec() const {
  return display_vec_;
}
void Computer::SetDisplayVec(std::unique_ptr<Display> &display_ptr) {
  display_vec_.push_back(std::move(display_ptr));
}

const std::vector<std::unique_ptr<Keyboard>> &Computer::GetKeyboardVec() const {
  return keyboard_vec_;
}
void Computer::SetKeyboardVec(std::unique_ptr<Keyboard> &keyboard_ptr) {
  keyboard_vec_.push_back(std::move(keyboard_ptr));
}

Builder::~Builder() = default;

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
void Builder::MakeOrderDesc(const std::string &desc) { std::cout << "unknown implementation"; }

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
  // 可以按照自己的顺序来建造，以及不同数量
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

LenovoBuilder::LenovoBuilder() = default;
void LenovoBuilder::MakeCpu() {
  std::unique_ptr<Cpu> one(new Intel());
  computer_.SetCpuVec(one);
  std::cout << "MakeCpu ";
}
void LenovoBuilder::MakeMemory() {
  std::unique_ptr<Memory> one(new Samsung());
  computer_.SetMemoryVec(one);
  std::cout << "MakeMemory ";
}

void LenovoBuilder::MakeHardDisk() {
  std::unique_ptr<HardDisk> one(new WesternDatabase());
  computer_.SetHardDiskVec(one);
  std::cout << "MakeHardDisk ";
}

void LenovoBuilder::MakeDisplay() {
  std::unique_ptr<Display> one(new Samsung());
  computer_.SetDisplayVec(one);
  std::cout << "MakeDisplay ";
}

void LenovoBuilder::MakeKeyboard() {
  std::unique_ptr<Keyboard> one(new Lenovo());
  computer_.SetKeyboardVec(one);
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
  ret.append("LenovoBuilder{");
  ret.append("make_order_desc=").append(make_order_desc_);
  ret.append("|").append(computer_.to_string());
  ret.append("}");
  return ret;
}

DellBuilder::DellBuilder() = default;
void DellBuilder::MakeCpu() {
  std::unique_ptr<Cpu> one(new Amd());
  computer_.SetCpuVec(one);
  std::cout << "MakeCpu ";
}
void DellBuilder::MakeMemory() {
  std::unique_ptr<Memory> one(new Kingston());
  computer_.SetMemoryVec(one);
  std::cout << "MakeMemory ";
}

void DellBuilder::MakeHardDisk() {
  std::unique_ptr<HardDisk> one(new Seagate());
  computer_.SetHardDiskVec(one);
  std::cout << "MakeHardDisk ";
}

void DellBuilder::MakeDisplay() {
  std::unique_ptr<Display> one(new Philips());
  computer_.SetDisplayVec(one);
  std::cout << "MakeDisplay ";
}

void DellBuilder::MakeKeyboard() {
  std::unique_ptr<Keyboard> one(new Logitech());
  computer_.SetKeyboardVec(one);
  std::cout << "MakeKeyboard ";
}

std::string DellBuilder::to_string() {
  std::string ret;
  ret.reserve(128);
  ret.append("DellBuilder{");
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

Cpu::~Cpu() = default;
std::string Cpu::to_string() { return "unknown Cpu"; }
std::string Intel::to_string() { return "Intel"; }
std::string Amd::to_string() { return "Amd"; }

Memory::~Memory() = default;
std::string Memory::to_string() { return "unknown Memory"; }
std::string Samsung::to_string() { return "Samsung"; }
std::string Kingston::to_string() { return "Kingston"; }

HardDisk::~HardDisk() = default;
std::string HardDisk::to_string() { return "unknown HardDisk"; }
std::string WesternDatabase::to_string() { return "WesternData"; }
std::string Seagate::to_string() { return "Seagate"; }

Display::~Display() = default;
std::string Display::to_string() { return "unknown Display"; }
std::string Philips::to_string() { return "Philips"; }

Keyboard::~Keyboard() = default;
std::string Keyboard::to_string() { return "unknown Keyboard"; }
std::string Lenovo::to_string() { return "Lenovo"; }
std::string Logitech::to_string() { return "Logitech"; }