#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <random>

class Sensor {
 public:
  Sensor() noexcept;
  ~Sensor() noexcept = default;

  // Returns temperature in Celsius
  double read_value() noexcept;

 private:
  // pure value types - safely copyable/movable
  std::mt19937 rng_;
  std::uniform_real_distribution<double> dist_;
};

#endif