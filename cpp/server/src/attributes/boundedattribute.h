#ifndef FOB_SERVER_ATTRIBUTES_BOUNDEDATTRIBUTE_H
#define FOB_SERVER_ATTRIBUTES_BOUNDEDATTRIBUTE_H

namespace fob {
namespace server {
namespace attributes {

class BoundedAttribute{
 public:
  BoundedAttribute(int min, int max, int current);
  virtual ~BoundedAttribute();

  int min() const;
  int max() const;
  int current() const;

  void set_min(int min);
  void set_max(int max);
  void set_current(int current);

  void Add(int value);
  void Subtract(int value);

 private:
  int min_, max_;
  int current_;
};

}  // namespace attributes
}  // namespace server
}  // namespace fob

#endif  // FOB_SERVER_ATTRIBUTES_BOUNDEDATTRIBUTE_H
