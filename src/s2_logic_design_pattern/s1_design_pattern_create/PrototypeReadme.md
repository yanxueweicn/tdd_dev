# Prototype Pattern Demo

# 1、需求说明

生成一个邮件模板，可以根据不同类型的接收人，只作简单修改主题就可以发送不同的人

# 2、任务分解

## 2.1、产生邮件对象

### 2.1.1、邮件包含：接收人、发送人、主题、邮件正文、附件等

## 2.2、每个不同类型的接收人名不同且显示主题不同

## 2.3、邮件生成后，就直接发送

# 3、测试用例

## 3.1、正常的

```
  // 先生成邮件模板
  Mail mail("company_x@tencent.com",
            "cp@tencent.com",
            "welcome [shenzhen] participant join",
            "Hello,welcome to tencent new product show!");
  EXPECT_STREQ(mail.to_string().c_str(),
               "Mail{receivers=company_x@tencent.com,sender=cp@tencent.com,subject=welcome [shenzhen] participant join,"
               "content=Hello,welcome to tencent new product show!}");

// 对company_a(北京),company_b(上海)复制发送
  std::unique_ptr<Mail> mail_bj((Mail *) mail.Clone());
  mail_bj->set_receivers("company_a@tencent.com").set_subject("welcome [beijing] participant join");
  EXPECT_STREQ(mail_bj->to_string().c_str(),
               "Mail{receivers=company_a@tencent.com,sender=cp@tencent.com,subject=welcome [beijing] participant join,"
               "content=Hello,welcome to tencent new product show!}");
// 发送
  MailSend(*mail_bj);

  std::unique_ptr<Mail> mail_sh((Mail *) mail.Clone());
  mail_sh->set_receivers("company_b@tencent.com").set_subject("welcome [shanghai] participant join");
  EXPECT_STREQ(mail_sh->to_string().c_str(),
               "Mail{receivers=company_b@tencent.com,sender=cp@tencent.com,subject=welcome [shanghai] participant join,"
               "content=Hello,welcome to tencent new product show!}");

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