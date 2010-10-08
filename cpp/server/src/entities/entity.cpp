#include "entity.h"

Entity::Entity(const boost::uuids::uuid &uid, std::string name)
    : uid_(uid),
      name_(name) {}

Entity::~Entity() {}

const boost::uuids::uuid &Entity::uid() const {
  return uid_;
}

const std::string &Entity::name() const {
  return name_;
}

int strength() const {
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

const RangeAttribute &Entity::damage() const {
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

const BoundedAttribute &mp() const {
  return mp_;
}

const BoundedAttribute &hp() const {
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
