#include <catch2/catch_test_macros.hpp>

#include <engine/core.h>

TEST_CASE("Vector3 can be constructed", "[core]") {
  whirlwind::Vector3 v(1, 2, 3);

  REQUIRE(v.x == 1);
  REQUIRE(v.y == 2);
  REQUIRE(v.z == 3);
}
