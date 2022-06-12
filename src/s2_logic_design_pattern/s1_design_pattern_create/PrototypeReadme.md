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
Mail mail(company_a@tencent.com,cp@tencent.com,"诚邀[北京分公司]参加新品分布会","您好，诚挚邀请前来参加腾讯公司新产品XXX大会！");
EXPECT_STREQ(mail.to_string().c_str(),
    "Mail={receivers=company_x@tencent.com,sender=cp@tencent.com"",subject=诚邀[XX分公司]参加新品分布会,"
    "content=您好，诚挚邀请前来参加腾讯公司新产品XXX大会！}");
    
// 对company_a(北京),company_b(上海),company_c(深圳)复制发送
Mail mail_bj=mail.clone();
mail_bj.set_receivers(company_a@tencent.com).set_subject_var1("北京")；
EXPECT_STREQ(mail_bj.to_string().c_str(),
    "Mail={receivers=company_a@tencent.com,sender=cp@tencent.com"",subject=诚邀[北京分公司]参加新品分布会,"
    "content=您好，诚挚邀请前来参加腾讯公司新产品XXX大会！}");
MailSend(mail_bj); 
    
Mail mail_sh=mail.clone();
mail_sh.set_receivers(company_b@tencent.com).set_subject_var1("上海");
EXPECT_STREQ(mail_sh.to_string().c_str(),
    "Mail={receivers=company_a@tencent.com,sender=cp@tencent.com"",subject=诚邀[上海分公司]参加新品分布会,"
    "content=您好，诚挚邀请前来参加腾讯公司新产品XXX大会！}");
MailSend(mail_sh); 
    
Mail mail_sz=mail.clone();
mail_sz.set_receivers(company_b@tencent.com).set_subject_var1("深圳");
EXPECT_STREQ(mail_sz.to_string().c_str(),
    "Mail={receivers=company_c@tencent.com,sender=cp@tencent.com"",subject=诚邀[深圳分公司]参加新品分布会,"
    "content=您好，诚挚邀请前来参加腾讯公司新产品XXX大会！}");
// 发送
MailSend(mail_sz); 
    

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