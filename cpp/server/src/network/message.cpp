#include "message.h"

#include <boost/uuid/uuid_io.hpp>

namespace fob {
namespace server {
namespace network {

Message::Message(MessageType type)
  : content_(std::ios_base::out
             | std::ios_base::in
             | std::ios_base::binary) {
  content_ << type << std::endl;
}

Message::Message(const std::string &content)
  : content_(content, std::ios_base::out
                      | std::ios_base::in
                      | std::ios_base::binary) {}

Message::~Message() {}

std::string Message::GetString() {
  return content_.str();
}

void Message::Inject(int var) {
  content_ << var << std::endl;
}

void Message::Inject(const std::string &var) {
  content_ << var << std::endl;
}

void Message::Inject(const boost::uuids::uuid &var) {
  content_ << var << std::endl;
}

Message::MessageType Message::GetType() {
  int ret_val;
  content_.seekg(0, std::ios_base::beg);
  content_ >> ret_val;
  char *temp = new char[16];
  content_.getline(temp, 16);
  delete temp;
  return (MessageType)ret_val;
}

void Message::Extract(int &var) {
  content_ >> var;
  char *temp = new char[16];
  content_.getline(temp, 16);
  delete temp;
}

void Message::Extract(std::string &var) {
  char *ret_val = new char[256];
  content_.getline(ret_val, 256);
  var = ret_val;
  delete ret_val;
}

void Message::Extract(boost::uuids::uuid &var) {
  content_ >> var;
  char *temp = new char[16];
  content_.getline(temp, 16);
  delete temp;
}

}  // namespace network
}  // namespace server
}  // namespace fob
