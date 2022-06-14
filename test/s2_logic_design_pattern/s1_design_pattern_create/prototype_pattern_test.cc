//
// Created by fanyan on 2022/6/14.
//
#include "src/s2_logic_design_pattern/s1_design_pattern_create/prototype_pattern.h"
#include "gtest/gtest.h"

namespace {
void MailSend(const Mail &src) {
  std::cout << " Mail Send...!" << std::endl;
}
}

TEST(Mail, NoramlSend) {
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
  EXPECT_STREQ(mail.to_string().c_str(),
               "Mail{receivers=company_x@tencent.com,sender=cp@tencent.com,subject=welcome [shenzhen] participant join,"
               "content=Hello,welcome to tencent new product show!}");
// 发送
  MailSend(*mail_bj);

  std::unique_ptr<Mail> mail_sh((Mail *) mail.Clone());
  mail_sh->set_receivers("company_b@tencent.com").set_subject("welcome [shanghai] participant join");
  EXPECT_STREQ(mail.to_string().c_str(),
               "Mail{receivers=company_x@tencent.com,sender=cp@tencent.com,subject=welcome [shenzhen] participant join,"
               "content=Hello,welcome to tencent new product show!}");
}