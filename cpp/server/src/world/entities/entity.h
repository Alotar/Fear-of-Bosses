#ifndef FOB_SERVER_ENTITIES_ENTITY_H_
#define FOB_SERVER_ENTITIES_ENTITY_H_

#include <string>

#include <boost/uuid/uuid.hpp>

#include "attributes/boundedattribute.h"
#include "attributes/rangeattribute.h"

namespace fob {
namespace server {
namespace world {
namespace entities {

class Entity {
 public:
  Entity(const boost::uuids::uuid &uid,const std::string &name);
  virtual ~Entity();

  const boost::uuids::uuid &uid() const;
  const std::string &name() const;

  int strength() const;
  int dexterity() const;
  int intelligence() const;
  int endurance() const;

  const ::fob::server::attributes::RangeAttribute &damage() const;
  int accuracy() const;
  int evasion() const;
  int m_dammage() const;
  int m_absorption() const;
  const ::fob::server::attributes::BoundedAttribute &mp() const;
  const ::fob::server::attributes::BoundedAttribute &hp() const;
  int speed() const;

 protected:
  void set_strength(int strength);
  void set_dexterity(int dexterity);
  void set_intelligence(int intelligence);
  void set_endurance(int endurance);
  void set_speed(int speed);

 private:
  const boost::uuids::uuid uid_;
  const std::string name_;

  int strength_;
  int dexterity_;
  int intelligence_;
  int endurance_;

  ::fob::server::attributes::RangeAttribute damage_;
  int accuracy_;
  int evasion_;
  int m_dammage_;
  int m_absorption_;
  ::fob::server::attributes::BoundedAttribute mp_;
  ::fob::server::attributes::BoundedAttribute hp_;
  int speed_;
};

}  // namespace entities
}  // namespace world
}  // namespace server
}  // namespace fob

#endif // FOB_SERVER_ENTITIES_ENTITY_H_
