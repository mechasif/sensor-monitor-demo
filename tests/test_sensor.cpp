#include <catch2/catch_test_macros.hpp>

#include "../src/Sensor.hpp"

TEST_CASE("Sensor generates temperature in valid range", "[sensor]") {
  Sensor sensor;

  for (int i = 0; i < 100; i++) {
    double temp = sensor.read_value();
    REQUIRE(temp >= 20.0);
    REQUIRE(temp <= 30.0);
  }
}