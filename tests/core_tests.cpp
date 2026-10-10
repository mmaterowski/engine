#include <catch2/catch_test_macros.hpp>

#include <engine/core.h>

TEST_CASE("Vector3 can be constructed", "[core]") {
  whirlwind::Vector3 v(1, 2, 3);

  REQUIRE(v.x == 1);
  REQUIRE(v.y == 2);
  REQUIRE(v.z == 3);
}

TEST_CASE("Vector3 can be muliplied", "[core]") {
  whirlwind::Vector3 v(1, 2, 3);
  v = v * 2;
  REQUIRE(v.x == 2);
  REQUIRE(v.y == 4);
  REQUIRE(v.z == 6);
}

TEST_CASE("Vector3 can be added to other Vector3 ", "[core]") {
  whirlwind::Vector3 v(1, 2, 3);
  whirlwind::Vector3 e(1, 2, 3);
  whirlwind::Vector3 z = v + e;
  REQUIRE(z.x == 2);
  REQUIRE(z.y == 4);
  REQUIRE(z.z == 6);
}

TEST_CASE("Vector3 can be modified in place by adding other Vector3 ",
          "[core]") {
  whirlwind::Vector3 v(1, 2, 3);
  whirlwind::Vector3 e(1, 2, 3);
  v += e;
  REQUIRE(v.x == 2);
  REQUIRE(v.y == 4);
  REQUIRE(v.z == 6);
}

TEST_CASE("Vector3 can be substracted to other Vector3 ", "[core]") {
  whirlwind::Vector3 v(2, 3, 4);
  whirlwind::Vector3 e(1, 2, 3);
  whirlwind::Vector3 z = v - e;
  REQUIRE(z.x == 1);
  REQUIRE(z.y == 1);
  REQUIRE(z.z == 1);
}

TEST_CASE("Vector3 can be modified in place by subtracting other Vector3 ",
          "[core]") {
  whirlwind::Vector3 v(2, 3, 4);
  whirlwind::Vector3 e(1, 2, 3);
  v -= e;
  REQUIRE(v.x == 1);
  REQUIRE(v.y == 1);
  REQUIRE(v.z == 1);
}

TEST_CASE("add Scaled Vector3 to Vector3 ", "[core]") {
  whirlwind::Vector3 v(2, 3, 4);
  v.addScaledVector(whirlwind::Vector3(1, 2, 3), 2);
  REQUIRE(v.x == 4);
  REQUIRE(v.y == 7);
  REQUIRE(v.z == 10);
}

TEST_CASE("calculate component product of two vectors ", "[core]") {
  whirlwind::Vector3 v(2, 3, 4);
  whirlwind::Vector3 e(1, 2, 3);
  whirlwind::Vector3 result = v.componentProduct(e);
  REQUIRE(result.x == 2);
  REQUIRE(result.y == 6);
  REQUIRE(result.z == 12);
}

TEST_CASE("update Vector3 cooridnates using component product ", "[core]") {
  whirlwind::Vector3 v(2, 3, 4);
  whirlwind::Vector3 e(1, 2, 3);
  v.componentProductUpdate(e);
  REQUIRE(v.x == 2);
  REQUIRE(v.y == 6);
  REQUIRE(v.z == 12);
}

TEST_CASE("calculates scalar product of two vectors", "[core]") {
  whirlwind::Vector3 v(2, 3, 4);
  whirlwind::Vector3 e(1, 2, 3);
  whirlwind::real result = v.scalarProduct(e);
  REQUIRE(result == 20);
}

TEST_CASE("calculates scalar product of two vectors using '*' operator",
          "[core]") {
  whirlwind::Vector3 v(2, 3, 4);
  whirlwind::Vector3 e(1, 2, 3);
  whirlwind::real result = v * e;
  REQUIRE(result == 20);
}

TEST_CASE("calculates vector product using class method", "[core]") {
  whirlwind::Vector3 v(2, 3, 4);
  whirlwind::Vector3 e(1, 2, 3);
  whirlwind::Vector3 result = v.vectorProduct(e);
  REQUIRE(result == whirlwind::Vector3(1, -2, 1));
}

TEST_CASE("calculates vector product using '%' operator", "[core]") {
  whirlwind::Vector3 v(2, 3, 4);
  whirlwind::Vector3 e(1, 2, 3);
  whirlwind::Vector3 result = v % e;
  REQUIRE(result == whirlwind::Vector3(1, -2, 1));
}

TEST_CASE("calculates vector product using '%=' operator", "[core]") {
  whirlwind::Vector3 v(2, 3, 4);
  whirlwind::Vector3 e(1, 2, 3);
  v %= e;
  REQUIRE(v == whirlwind::Vector3(1, -2, 1));
}
