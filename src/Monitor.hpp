#ifndef MONITOR_HPP
#define MONITOR_HPP

#include "Sensor.hpp"
#include "WebAPI.hpp"

class Monitor {
 public:
  Monitor() noexcept = default;
  ~Monitor() noexcept = default;

  Monitor(const Monitor&) = delete;
  Monitor& operator=(const Monitor&) = delete;
  Monitor(Monitor&&) = delete;
  Monitor& operator=(Monitor&&) = delete;

  void run(const std::atomic<bool>& running_flag);

 private:
  Sensor sensor_{};
  WebAPI webapi_{};
};

#endif