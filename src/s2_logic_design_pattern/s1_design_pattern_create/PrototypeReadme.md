# Prototype Pattern Demo

# 1、需求说明

生成一个邮件模板，可以根据不同类型的接收人，只作简单修改主题就可以发送不同的人

# 2、任务分解

## 2.1、产生邮件对象

### 2.1.1、邮件包含：接收人、发送人、主题、邮件正文、附件等

## 2.2、每个不同类型的接收人名不同且显示主题不同

## 2.3、邮件生成后，就直接发送

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