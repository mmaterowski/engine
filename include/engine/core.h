#pragma once

#include <engine/precision.h>
#include <ostream>
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

  auto operator*(const real value) const -> Vector3 {
    return {x * value, y * value, z * value};
  }

  void operator+=(const Vector3 &v) {
    x += v.x;
    y += v.y;
    z += v.z;
  }

  auto operator+(const Vector3 &v) const -> Vector3 {
    return {x + v.x, y + v.y, z + v.z};
  }

  void operator-=(const Vector3 &v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
  }

  auto operator-(const Vector3 &v) const -> Vector3 {
    return {x - v.x, y - v.y, z - v.z};
  }

  void addScaledVector(const Vector3 &vector, real scale) {
    x += vector.x * scale;
    y += vector.y * scale;
    z += vector.z * scale;
  }

  [[nodiscard]] auto componentProduct(const Vector3 &vector) const -> Vector3 {
    return {x * vector.x, y * vector.y, z * vector.z};
  }

  void componentProductUpdate(const Vector3 &vector) {
    x *= vector.x;
    y *= vector.y;
    z *= vector.z;
  }

  [[nodiscard]] auto scalarProduct(const Vector3 &vector) const -> real {
    return (x * vector.x) + (y * vector.y) + (z * vector.z);
  }

  auto operator*(const Vector3 &vector) const -> real {
    return (x * vector.x) + (y * vector.y) + (z * vector.z);
  }

  [[nodiscard]] auto vectorProduct(const Vector3 &vector) const -> Vector3 {
    return {(y * vector.z) - (z * vector.y), (z * vector.x) - (x * vector.z),
            (x * vector.y) - (y * vector.x)};
  }

  void operator%=(const Vector3 &vector) { *this = vectorProduct(vector); }

  auto operator%(const Vector3 &vector) const -> Vector3 {
    return {(y * vector.z) - (z * vector.y), (z * vector.x) - (x * vector.z),
            (x * vector.y) - (y * vector.x)};
  }

  auto operator==(const Vector3 &vector) const -> bool {
    return (x == vector.x && y == vector.y && z == vector.z);
  }

  friend auto operator<<(std::ostream &os, const whirlwind::Vector3 &v)
      -> std::ostream & {
    return os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
  }
};
} // namespace whirlwind
