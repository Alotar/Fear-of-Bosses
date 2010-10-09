#include "entity.h"

namespace fob {
namespace server {
namespace entities {

Entity::Entity(const boost::uuids::uuid &uid, const std::string &name)
    : uid_(uid),
      name_(name),
      damage_(0,0),
      mp_(0,0,0),
      hp_(0,0,0) {}

Entity::~Entity() {}

const boost::uuids::uuid &Entity::uid() const {
  return uid_;
}

const std::string &Entity::name() const {
  return name_;
}

int Entity::strength() const {
  return strength_;
}

int Entity::dexterity() const {
  return dexterity_;
}

int Entity::intelligence() const {
  return intelligence_;
}

int Entity::endurance() const {
  return endurance_;
}

const ::fob::server::attributes::RangeAttribute &Entity::damage() const {
  return damage_;
}

int Entity::accuracy() const {
  return accuracy_;
}

int Entity::evasion() const {
  return evasion_;
}

int Entity::m_dammage() const {
  return m_dammage_;
}

int Entity::m_absorption() const {
  return m_absorption_;
}

const ::fob::server::attributes::BoundedAttribute &Entity::mp() const {
  return mp_;
}

const ::fob::server::attributes::BoundedAttribute &Entity::hp() const {
  return hp_;
}

int Entity::speed() const {
  return speed_;
}

void Entity::set_strength(int strength) {
  strength_ = strength;
}

void Entity::set_dexterity(int dexterity) {
  dexterity_ = dexterity;
}

void Entity::set_intelligence(int intelligence) {
  intelligence_ = intelligence;
}

void Entity::set_endurance(int endurance) {
  endurance_ = endurance;
}

void Entity::set_speed(int speed) {
  speed_ = speed;
}

} // namespace entities
} // namespace server
} // namespace fob
