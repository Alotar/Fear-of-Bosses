#include "rangeattribute.h"

namespace fob {
namespace server {
namespace entities {
namespace attributes {

RangeAttribute::RangeAttribute (int min, int max)
    : min_(min),
      max_(max) {
}

RangeAttribute::~RangeAttribute() {}

int RangeAttribute::min() const {
  return min_;
}

int RangeAttribute::max() const {
  return max_;
}

void set_min(int min) {
  min_ = min;
}

void set_max(int max) {
  max_ = max;
}

}  // namespace attributes
}  // namespace entities
}  // namespace server
}  // namespace fob
