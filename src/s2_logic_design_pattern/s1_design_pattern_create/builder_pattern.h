//
// Created by yanxuewei on 2022/6/3.
//

#ifndef TDD_DEMO_BUILDER_PATTERN_H
#define TDD_DEMO_BUILDER_PATTERN_H

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
  virtual std::string to_string();
  virtual Computer GetResult();
};

class Director {
public:
  explicit Director(const Builder &builder);

  Computer Construct();
};

class LenovoBuilder : public Builder {
public:
  virtual void MakeCpu() override;
  virtual void MakeHardDisk() override;
  virtual void MakeDisplay() override;
  virtual void MakeKeyboard() override;
  virtual std::string to_string() override;
  virtual Computer GetResult() override;

private:
};

class DellBuilder : public Builder {
public:
  virtual void MakeCpu() override;
  virtual void MakeMemory() override;
  virtual void MakeHardDisk() override;
  virtual void MakeDisplay() override;
  virtual void MakeKeyboard() override;
  virtual std::string to_string() override;
  virtual Computer GetResult() override;
};
#endif // TDD_DEMO_BUILDER_PATTERN_H
