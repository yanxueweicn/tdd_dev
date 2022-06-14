//
// Created by fanyan on 2022/6/14.
//

#include "prototype_pattern.h"
#include <cstring>

Mail::Mail(const std::string &receivers, const std::string &sender, const char *subject, const std::string &content)
    : receivers_(receivers), sender_(sender), content_(content) {
  subject_ = new char[512];
  strncpy(subject_, subject, 512);
}

Mail::Mail(const Mail &src) {
  receivers_.assign(src.receivers());
  sender_.assign(src.sender());
  subject_ = new char[512];
  strncpy(subject_, src.subject(), 512);
  content_.assign(src.content());
}

Mail::~Mail() {
  delete subject_;
  subject_ = nullptr;
}

Mail &Mail::set_receivers(const std::string &receivers) {
  receivers_.assign(receivers);
  return *this;
}
std::string Mail::receivers() const {
  return receivers_;
}

Mail &Mail::set_sender(const std::string &sender) {
  sender_.assign(sender);
  return *this;
}
std::string Mail::sender() const {
  return sender_;
}

Mail &Mail::set_subject(const char *subject) {
  memset((void *) subject_, 0, sizeof(512));
  strncpy(subject_, subject, 512);
  return *this;
}
const char *Mail::subject() const {
  return subject_;
}

Mail &Mail::set_content(const std::string &content) {
  content_.assign(content);
  return *this;
}
std::string Mail::content() const {
  return content_;
}

Prototype *Mail::Clone() {
  return new Mail(*this);
}
std::string Mail::to_string() {
  std::string ret;
  ret.reserve(128);
  ret.append("Mail{");
  ret.append("receivers=").append(receivers_);
  ret.append(",sender=").append(sender_);
  ret.append(",subject=").append(subject_);
  ret.append(",content=").append(content_);
  ret.append("}");
  return ret;
}

Resume &Resume::set_name(const std::string &name) {
  name_.assign(name);
  return *this;
}
std::string Resume::name() const {
  return name_;
}

Resume &Resume::set_is_boy(bool is_boy) {
  is_boy_ = is_boy;
  return *this;
}
bool Resume::is_boy() const {
  return is_boy_;
}

Resume &Resume::set_age(int age) {
  age_ = age;
  return *this;
}
int Resume::age() const {
  return age_;
}

Prototype *Resume::Clone() {
  return new Resume(*this);
}
std::string Resume::to_string() {
  std::string ret;
  ret.reserve(128);
  ret.append("Resume{");
  ret.append("name=").append(name_);
  ret.append(",is_boy=").append(std::to_string(is_boy_));
  ret.append(",age=").append(std::to_string(age_));
  ret.append("}");
  return ret;
}