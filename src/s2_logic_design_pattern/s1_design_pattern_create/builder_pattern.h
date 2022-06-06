//
// Created by yanxuewei on 2022/6/3.
//

#ifndef TDD_DEMO_BUILDER_PATTERN_H
#define TDD_DEMO_BUILDER_PATTERN_H

#include <memory>
#include <string>

class Computer {
 public:
  void InitSetup();

  void SetupGame();

  void GameStart();
};

class Builder {
 public:
  virtual void MakeCpu();

  virtual void MakeMemory();

  virtual void MakeHardDisk();

  virtual void MakeDisplay();

  virtual void MakeKeyboard();

  virtual Computer *GetResult();

  // extend method for debug
  virtual std::string to_string();

  virtual void MakeOrderDesc(const std::string &desc);
};

class Director {
 public:
  explicit Director(const Builder &builder);

  Computer *Construct();

  Computer *ConstructStrong();

 private:
  Builder &builder_;
};

class Cpu {
 public:
  virtual std::string to_string();
};

class Intel : public Cpu {
 public:
  std::string to_string() override;
};

class Amd : public Cpu {
 public:
  std::string to_string() override;
};

class Memory {
 public:
  virtual std::string to_string();
};

// class Samsung : public Memory {};
class Kingston : public Memory {
 public:
  std::string to_string() override;
};

class HardDisk {
 public:
  virtual std::string to_string();
};

class WesternDatabase : public HardDisk {
 public:
  std::string to_string() override;
};

class Seagate : public HardDisk {
 public:
  std::string to_string() override;
};

class Display {
 public:
  virtual std::string to_string();
};

class Samsung : public Memory, public Display {
 public:
  std::string to_string() override;
};

class Philips : public Display {
 public:
  std::string to_string() override;
};

class Keyboard {
 public:
  virtual std::string to_string();
};

class Lenovo : public Keyboard {
 public:
  std::string to_string() override;
};

class Logitech : public Keyboard {
 public:
  std::string to_string() override;
};

class LenovoBuilder : public Builder {
 public:
  LenovoBuilder();

  void MakeCpu() override;

  void MakeMemory() override;

  void MakeHardDisk() override;

  void MakeDisplay() override;

  void MakeKeyboard() override;

  Computer *GetResult() override;

  std::string to_string() override;

  void MakeOrderDesc(const std::string &desc) override;

 private:
  Computer computer_;
  //
  std::unique_ptr<Cpu> cpu_;
  std::unique_ptr<Memory> memory_;
  std::unique_ptr<HardDisk> hard_disk_;
  std::unique_ptr<Display> display_;
  std::unique_ptr<Keyboard> keyboard_;
  //
  std::string make_order_desc_;
};

class DellBuilder : public Builder {
 public:
  DellBuilder();

  void MakeCpu() override;

  void MakeMemory() override;

  void MakeHardDisk() override;

  void MakeDisplay() override;

  void MakeKeyboard() override;

  Computer *GetResult() override;

  std::string to_string() override;

  void MakeOrderDesc(const std::string &desc) override;

 private:
  Computer computer_;
  //
  std::unique_ptr<Cpu> cpu_;
  std::unique_ptr<Memory> memory_;
  std::unique_ptr<HardDisk> hard_disk_;
  std::unique_ptr<Display> display_;
  std::unique_ptr<Keyboard> keyboard_;
  //
  std::string make_order_desc_;
};

#endif // TDD_DEMO_BUILDER_PATTERN_H