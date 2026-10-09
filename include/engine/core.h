#pragma once

#include <engine/precision.h>
namespace whirlwind {
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

  void operator+=(const Vector3 &v) {
    x += v.x;
    y += v.y;
    z += v.z;
  }

  Vector3 operator+(const Vector3 &v) const {
    return Vector3(x + v.x, y + v.y, z + v.z);
  }

  void operator-=(const Vector3 &v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
  }

  Vector3 operator-(const Vector3 &v) const {
    return Vector3(x - v.x, y - v.y, z - v.z);
  }

  void addScaledVector(const Vector3 &vector, real scale) {
    x += vector.x * scale;
    y += vector.y * scale;
    z += vector.z * scale;
  }
};
} // namespace whirlwind
