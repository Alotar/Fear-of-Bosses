#include "boundedattribute.h"

namespace fob {
namespace server {
namespace attributes {

BoundedAttribute::BoundedAttribute(int min, int max, int current)
    : min_(min),
      max_(max),
      current_(current) {
  if (max < min) {
    max_ = min;
  }
  if (current < min) {
    current_ = min;
  }
  if (current > max) {
    current_ = max;
  }
}

BoundedAttribute::~BoundedAttribute() {}

int BoundedAttribute::min() const {
  return min_;
}

int BoundedAttribute::max() const {
  return max_;
}

int BoundedAttribute::current() const {
  return current_;
}

void BoundedAttribute::set_min(int min) {
  if (min > max_) {
    min_ = max_;
  } else {
    min_ = min;
  }
  if (current_ < min_){
    current_ = min_;
  }
}

void BoundedAttribute::set_max(int max) {
  if (max < min_) {
    max_ = min_;
  } else {
    max_ = max;
  }
  if (current_ > max_) {
    current_ = max_;
  }
}

void BoundedAttribute::set_current(int current) {
  if (current > max_) {
    current_ = max_;
  } else if (current < min_) {
    current_ = min_;
  } else {
    current_ = current;
  }
}

void BoundedAttribute::Add(int value) {
  set_current(current_ + value);
}

void BoundedAttribute::Subtract(int value) {
  set_current(current_ - value);
}

}  // namespace attributes
}  // namespace server
}  // namespace fob
