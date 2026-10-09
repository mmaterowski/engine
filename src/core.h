#include "precision.h"
namespace cyclone {
class Vector3 {
public:
  real x;
  real y;
  real z;

private:
  // Padding to ensure four world alignment
  real pad;

public:
  Vector3() : x(0), y(0), z(0) {}

  Vector3(const real x, const real y, const real z) : x(x), y(y), z(z) {}

  void invert() {
    x = -x;

    y = -y;
    z = -z;
  }

  Vector3 operator*(const real value) const {
    return Vector3(x * value, y * value, z * value);
  }
};
} // namespace cyclone
