//
// Created by yanxuewei on 2021/8/7.
//

#include "comm/comm.h"
#include "comm/simple_object_pool.h"

#include "gtest/gtest.h"

TEST(DisplayBegin, IsNotEmpty) {
    
    std::string ret = display_begin();
    EXPECT_FALSE(ret.empty());
    
    
}

//TEST(DisplayEnd, IsNotEmpty) {
//    std::string ret = display_end();
//    EXPECT_FALSE(ret.empty());
//}
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
    TestClass test_one("fanyan", 42);
    TestClass test_two("yxw", 24);
    TestClass test_three(test_one);
    
    test_two = test_one;
    EXPECT_STREQ(test_one.ToString().c_str(), "{name='fanyan',age=42}");
    
}

class TestObject {
public:
    TestObject() : age(0), address_ptr(new std::string()) {
        std::cout << " Ctor\n";
    }
    
    TestObject(const TestObject &other) : age(other.age), name(other.name), address_ptr(other.address_ptr) {
        std::cout << " CopyCtor\n";
    }
    
    ~TestObject() {
        std::cout << " Dctor\n";
        
    }
    
    void ReSet() {
        age = 0;
        name.clear();
        // other
        address_ptr->clear();
    }
    
    std::string ToString() const {
        std::string ret;
        ret.reserve(64);
        
        ret.append("{");
        ret.append("age=").append(std::to_string(age));
        ret.append(",name=").append(name);
        ret.append(",address=").append(*address_ptr);
        ret.append("}");
        
        return ret;
        
    }
    
    void RefInvoke(const TestObject &other) {
        std::cout << " RefInvoke!\n";
    }
    
    void CopyConstructor(const TestObject other) {
        std::cout << " CopyConstructor!\n";
    }
    
    int age;
    std::string name;
    std::shared_ptr<std::string> address_ptr;
};

TEST(SimpleObjectPool, Normal) {
    SimpleObjectPool<TestObject> sop(2);
    
    TestObject *one = sop.Get();
    EXPECT_STREQ(one->ToString().c_str(), "{age=0,name=,address=}");
    
    one->age = 10;
    one->name = "lele";
    one->address_ptr->assign("shenzhen");
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
        // using very operator
        
        EXPECT_STREQ(sop.ToString().c_str(), "{pool_size=1,make_pool_size=2}");
        
    }
    EXPECT_STREQ(sop.ToString().c_str(), "{pool_size=2,make_pool_size=2}");
    
}