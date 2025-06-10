#include "Sensor.hpp"

#include <chrono>

// Simulate temperature between 20 to 30 °C
Sensor::Sensor() noexcept
    : rng_(static_cast<unsigned>(
          std::chrono::steady_clock::now().time_since_epoch().count())),
      dist_(20.0, 30.0) {}

double Sensor::read_value() noexcept { return dist_(rng_); }