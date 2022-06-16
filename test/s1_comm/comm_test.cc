//
// Created by yanxuewei on 2021/8/7.
//

#include "s1_comm/comm.h"
#include "s1_comm/simple_object_pool.h"
#include "s1_comm/template_meta_program.h"

#include "gtest/gtest.h"

TEST(DisplayBegin, IsNotEmpty) {

  std::string ret = display_begin();
  EXPECT_FALSE(ret.empty());

}

//TEST(DisplayEnd, IsNotEmpty) {
//    std::string ret = display_end();
//    EXPECT_FALSE(ret.empty());
//}

class TestObject {
 public:
  TestObject() : age_(0), address_ptr_(new std::string()) {
    std::cout << " Ctor\n";
  }

  TestObject(int age, const string &name) : age_(age), name_(name), address_ptr_(new std::string()) {}

  TestObject(const TestObject &other) : age_(other.age_), name_(other.name_), address_ptr_(other.address_ptr_) {
    std::cout << " CopyCtor\n";
  }

  ~TestObject() {
    std::cout << " Dctor\n";

  }

  void ReSet() {
    age_ = 0;
    name_.clear();
    // other
    address_ptr_->clear();
  }

  void RefInvoke(const TestObject &other) {
    std::cout << " RefInvoke!\n";
  }

  void CopyConstructor(const TestObject other) {
    std::cout << " CopyConstructor!\n";
  }

  std::string ToString() const {
    std::string ret;
    ret.reserve(64);

    ret.append("{");
    ret.append("age=").append(std::to_string(age_));
    ret.append(",name=").append(name_);
    ret.append(",address=").append(*address_ptr_);
    ret.append("}");

    return ret;

  }

  void MakeTestObject(int age, const std::string &name, const std::string &address) {
    age_ = age;
    name_ = name;
    address_ptr_->assign(address);
  }

 private:
  int age_;
  std::string name_;
  std::shared_ptr<std::string> address_ptr_;
};

TEST(TestClass, RefAndConstField) {
  // test ref is not transfer
  int a = 2;
  int &b = a;
  EXPECT_EQ(b, a);

  int c = 5;
  b = c;
  EXPECT_EQ(b, c);
  EXPECT_EQ(a, b);
  EXPECT_EQ(a, 5);

  ++b;
  EXPECT_EQ(b, 6);
  EXPECT_EQ(c, 5);

  // test const field and ref field can't use default constructor&assignment method
  TestObject test_one(42, "fanyan");

  TestObject test_two(24, "yxw");
  TestObject test_three(test_one);

  test_two = test_one;
  EXPECT_STREQ(test_one.ToString().c_str(), "{age=42,name=fanyan,address=}");

}

TEST(SimpleObjectPool, Normal) {
  SimpleObjectPool<TestObject> sop(2);

  TestObject *one = sop.Get();
  EXPECT_STREQ(one->ToString().c_str(), "{age=0,name=,address=}");

  one->MakeTestObject(10, "lele", "shenzhen");
  EXPECT_STREQ(one->ToString().c_str(), "{age=10,name=lele,address=shenzhen}");

  //judge ref or copy test
  TestObject test_object;
  one->RefInvoke(test_object);

  one->CopyConstructor(test_object);

  // using other logic
  sop.Return(one);
  EXPECT_STREQ(one->ToString().c_str(), "{age=0,name=,address=}");

  one = sop.Get();
  EXPECT_STREQ(one->ToString().c_str(), "{age=0,name=,address=}");
  sop.Return(one);

}

TEST(ObjectPoolTool, Normal) {
  SimpleObjectPool<TestObject> sop(2);
  EXPECT_STREQ(sop.ToString().c_str(), "{pool_size=2,make_pool_size=2}");
  {
    ObjectPoolTool<TestObject> pool_tool(sop);
    TestObject *one = pool_tool.Get();
    EXPECT_STREQ(sop.ToString().c_str(), "{pool_size=1,make_pool_size=2}");

    EXPECT_STREQ(one->ToString().c_str(), "{age=0,name=,address=}");
    // using very operator
    one->MakeTestObject(42, "fanyan", "sz");
    EXPECT_STREQ(one->ToString().c_str(), "{age=42,name=fanyan,address=sz}");

  }
  EXPECT_STREQ(sop.ToString().c_str(), "{pool_size=2,make_pool_size=2}");

}

TEST(TmpDemo, IsRun) {
  TmpDemo<bool, true, SimpleObjectPool, int> tmp_deom;
}

TEST(TmpDemoFunction, IsSame) {
  bool ret = std::is_same<int, int32_t>::value;
  EXPECT_TRUE(ret);

  ret = std::is_same<short, int>::value;
  EXPECT_FALSE(ret);

  ret = std::is_same<const char *, const char[]>::value;
  EXPECT_FALSE(ret);

  ret = std::is_same<std::is_same<bool, bool>, std::true_type>::value;
  EXPECT_FALSE(ret);
}

TEST(TmpDemoFunc, IsVarArgs) {
  EXPECT_STREQ(TmpDemoFunction("fanyan", " game!").c_str(), "fanyan game!");
  EXPECT_STREQ(TmpDemoFunction(1, 9).c_str(), "19");
  EXPECT_STREQ(TmpDemoFunction(1, 9.99).c_str(), "19.990000");
  //
}