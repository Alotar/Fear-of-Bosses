#ifndef FOB_SERVER_ENTITIES_ENTITY_H_
#define FOB_SERVER_ENTITIES_ENTITY_H_

#include <string>

#include "attributes/boundedattribute.h"
#include "attributes/rangeattribute.h"

namespace fob {
namespace server {
namespace entities {

class Entity {
 public:
  virtual Entity(std::string uid, std::string name);
  virtual ~Entity();

  const std::string &uid() const;
  const std::string &name() const;

  int strength() const;
  int dexterity() const;
  int intelligence() const;
  int endurance() const;

  const RangeAttribute &damage() const;
  int accuracy() const;
  int evasion() const;
  int m_dammage() const;
  int m_absorption() const;
  const BoundedAttribute &mp() const;
  const BoundedAttribute &hp() const;
  int speed() const;

 protected:
  void set_strength(int strength);
  void set_dexterity(int dexterity);
  void set_intelligence(int intelligence);
  void set_endurance(int endurance);
  void set_speed(int speed);

 private:
  std::string uid_;
  std::string name_;

  int strength_;
  int dexterity_;
  int intelligence_;
  int endurance_;

  RangeAttribute damage_;
  int accuracy_;
  int evasion_;
  int m_dammage_;
  int m_absorption_;
  BoundedAttribute mp_;
  BoundedAttribute hp_;
  int speed_;
};

} // namespace entities
} // namespace server
} // namespace fob

#endif // FOB_SERVER_ENTITIES_ENTITY_H_
