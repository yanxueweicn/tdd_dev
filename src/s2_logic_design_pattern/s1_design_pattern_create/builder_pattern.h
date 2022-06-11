//
// Created by yanxuewei on 2022/6/3.
//

#ifndef TDD_DEMO_BUILDER_PATTERN_H
#define TDD_DEMO_BUILDER_PATTERN_H

#include <memory>
#include <string>
#include <vector>
#include <type_traits>

template<typename T, typename= typename std::enable_if<
    std::is_same<std::string, decltype(std::declval<T>().to_string())>::value>::type>
std::string to_string(const std::unique_ptr<T> &src) {
  std::string ret;
  ret.reserve(64);
  ret.append(src ? src->to_string() : "");
  return ret;
}

template<typename T, typename Collection=std::vector<std::unique_ptr<T>>,
    typename=typename std::enable_if<
        std::is_same<std::string, decltype(std::declval<T>().to_string())>::value>::type>
std::string to_string(const Collection &src) {
  std::string ret;
  ret.reserve(64);

  int i = 0;
  for (auto cit = src.begin(); cit != src.end(); ++cit, ++i) {
    if (i > 0) ret.append("_");
    ret.append(to_string(*cit));
  }

  return ret;
}

class Cpu;
class Memory;
class HardDisk;
class Display;
class Keyboard;
class Computer {
 public:
  void InitSetup();

  void SetupGame();

  void GameStart();

  const std::vector<std::unique_ptr<Cpu>> &GetCpuVec() const;
  void SetCpuVec(std::unique_ptr<Cpu> &cpu_ptr);

  const std::vector<std::unique_ptr<Memory>> &GetMemoryVec() const;
  void SetMemoryVec(std::unique_ptr<Memory> &memory_ptr);

  const std::vector<std::unique_ptr<HardDisk>> &GetHardDiskVec() const;
  void SetHardDiskVec(std::unique_ptr<HardDisk> &hard_disk_ptr);

  const std::vector<std::unique_ptr<Display>> &GetDisplayVec() const;
  void SetDisplayVec(std::unique_ptr<Display> &display_ptr);

  const std::vector<std::unique_ptr<Keyboard>> &GetKeyboardVec() const;
  void SetKeyboardVec(std::unique_ptr<Keyboard> &keyboard_ptr);

  // extend method for debug
  std::string to_string();

 private:
  //
  std::vector<std::unique_ptr<Cpu>> cpu_vec_;
  std::vector<std::unique_ptr<Memory>> memory_vec_;
  std::vector<std::unique_ptr<HardDisk>> hard_disk_vec_;
  std::vector<std::unique_ptr<Display>> display_vec_;
  std::vector<std::unique_ptr<Keyboard>> keyboard_vec_;
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
  std::string make_order_desc_;
};

#endif // TDD_DEMO_BUILDER_PATTERN_H