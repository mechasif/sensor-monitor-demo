#ifndef WEBAPI_HPP
#define WEBAPI_HPP

#include <httplib.h>

#include <atomic>
#include <chrono>
#include <mutex>
#include <thread>

#include "Logger.hpp"

class WebAPI {
 public:
  WebAPI() noexcept;
  ~WebAPI() noexcept;

  WebAPI(const WebAPI&) = delete;
  WebAPI& operator=(const WebAPI&) = delete;
  WebAPI(WebAPI&&) = delete;
  WebAPI& operator=(WebAPI&&) = delete;

  void start();
  void stop();
  void publish_sensor_value(double value);

 private:
  httplib::Server server_{};
  double latest_value_{0.0};
  std::mutex value_mutex_{};
  std::thread server_thread_{};
  std::atomic<bool> server_ready_{false};
  std::atomic<bool> server_running_{false};
  void setup_routes();
};

#endif