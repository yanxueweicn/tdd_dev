//
// Created by fanyan on 2022/6/14.
//

#ifndef TDD_DEV_SRC_S2_LOGIC_DESIGN_PATTERN_S1_DESIGN_PATTERN_CREATE_PROTOTYPE_PATTERN_H_
#define TDD_DEV_SRC_S2_LOGIC_DESIGN_PATTERN_S1_DESIGN_PATTERN_CREATE_PROTOTYPE_PATTERN_H_

#include <string>

class Prototype {
 public:
  virtual Prototype *Clone() = 0;
};

class Mail : public Prototype {
 public:
  Mail(const std::string &receivers, const std::string &sender,
       const char *subject, const std::string &content);
  Mail(const Mail &src);
  Mail &operator=(const Mail &src) = delete;
  ~Mail();

  Mail &set_receivers(const std::string &receivers);
  std::string receivers() const;

  Mail &set_sender(const std::string &sender);
  std::string sender() const;

  Mail &set_subject(const char *subject);
  const char *subject() const;

  Mail &set_content(const std::string &content);
  std::string content() const;

  Prototype *Clone() override;

  std::string to_string();

 private:
  std::string receivers_;
  std::string sender_;
  char *subject_;
  std::string content_;
};

class Resume : public Prototype {

  Resume &set_name(const std::string &name);

  std::string name() const;

  Resume &set_is_boy(bool is_boy);

  bool is_boy() const;

  Resume &set_age(int age);

  int age() const;

  Prototype *Clone() override;

  std::string to_string();

 private:
  std::string name_;
  bool is_boy_;
  int age_;
};

#endif //TDD_DEV_SRC_S2_LOGIC_DESIGN_PATTERN_S1_DESIGN_PATTERN_CREATE_PROTOTYPE_PATTERN_H_