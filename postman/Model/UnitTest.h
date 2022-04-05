/**
 * Project Untitled
 */

#ifndef _UNITTEST_H
#define _UNITTEST_H

class UnitTest {
public:
  const string &test_suit_name_;

  void UnitTest();

  void Operation1();

protected:
  void UnitTest();

private:
  /**
   * 显示测试用例的名称
   */
  const std::string &name_;

  void DoRun();
};

#endif //_UNITTEST_H