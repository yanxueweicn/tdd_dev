# Builder Pattern Demo

# 1、需求说明

制造一个计算机对象，可以玩游戏

# 2、任务分解

## 2.1、产生计算机对象

### 2.1.1、计算机包含主要部件：cpu、内存、硬盘、显示器、键盘...etc

### 2.1.2、计算机可以有多个组装厂家：联想、dell、惠普..etc

### 2.1.3、先生成好部件，再组装成一个计算机

### 2.1.4、然后初始化安装、安装游戏、再玩游戏

# 3、测试用例

```
// 用户使用联想
std::unique_ptr<Builder> builder(new LenovoBuilder());
Director director(*builder);
Computer* computer_ptr=director.Construt();
ComputerSetup(*computer_ptr);

// 另外一个用户使用dell
builder.reset(new DellBuilder());
Director director2(*builder);
computer_ptr=director2.ConstrutStrong();
ComputerSetup(*computer_ptr);
```

## 3.1、正常的

```
EXPECT_STREQ(builder.to_string().c_str(),
    "LenovoBuilder{make_order_desc=cpu->memory->hard_disk->keyboard->display"
    "|computer={cpu=Intel,memory=Samsung,hard_disk=WesternData,display=Samsung,keyboard=Lenovo}}")
EXPECT_STREQ(builder.to_string().c_str(),
    "DellBuilder{make_order_desc=2cpu->memory->2hard_disk->2display->keyboard"
    "|computer={cpu=Amd_Amd,memory=Kingston,hard_disk=Seagate_Seagate,display=Philips_Philips,keyboard=Logitech}}")

```

## 3.2、不正常的

```
#、有不支持的配件 unknown
EXPECT_TRUE(builder.to_string().find("unknown")!=std::string::npos)
```

### 3.2.1、值类型不对

### 3.2.2、极大值

### 3.2.3、极小值

# 4、编码

## 4.1、写好框架

## 4.2、定好方法和类名：画好类图

# 5、运行测试