#pragma once

#include <cmath>
#include <engine/precision.h>
#include <ostream>
using namespace std;
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

  [[nodiscard]] auto magnitude() const -> real {
    return sqrt((x * x) + (y * y) + (z * z));
  }

  [[nodiscard]] auto squareMagnitude() const -> real {
    return (x * x) + (y * y) + (z * z);
  }

  void normalize() {
    real l = magnitude();
    if (l > 0) {
      (*this) *= (static_cast<real>(1)) / l;
    }
  }

  // Multiplies Vector by scalar
  void operator*=(const real value) {
    x *= value;
    y *= value;
    z *= value;
  }

  // Returns copy of this Vector multiplied by scalar
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

  static void makeOrthonormalBasis(Vector3 *a, Vector3 *b, Vector3 *c) {
    a->normalize();
    (*c) = (*a) % (*b);
    if (c->squareMagnitude() == 0.0) {
      return;
    }
    c->normalize();
    (*b) = (*c) % (*a);
  }

  friend auto operator<<(ostream &os, const whirlwind::Vector3 &v)
      -> ostream & {
    return os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
  }
};
} // namespace whirlwind
