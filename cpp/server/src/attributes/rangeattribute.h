#ifndef FOB_SERVER_ATTRIBUTES_RANGEATTRIBUTE_H_
#define FOB_SERVER_ATTRIBUTES_RANGEATTRIBUTE_H_

namespace fob {
namespace server {
namespace attributes {

class RangeAttribute {
 public:
  RangeAttribute(int min, int max);
  virtual ~RangeAttribute();

  int min() const;
  int max() const;

  void set_min(int min);
  void set_max(int max);

 private:
  int min_;
  int max_;
};

}  // namespace attributes
}  // namespace server
}  // namespace fob

#endif  // FOB_SERVER_ATTRIBUTES_RANGEATTRIBUTE_H_
