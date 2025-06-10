#include "WebAPI.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <thread>

WebAPI::WebAPI() noexcept : latest_value_{0.0} { setup_routes(); }

WebAPI::~WebAPI() noexcept { stop(); }

void WebAPI::setup_routes() {
  server_.Get("/status",
              [this](const httplib::Request&, httplib::Response& res) {
                double value;
                {
                  std::lock_guard<std::mutex> lock(value_mutex_);
                  value = latest_value_;
                }

                std::ostringstream oss;
                oss << std::fixed << std::setprecision(2)
                    << "Current Sensor Value: " << value << " °C\n";
                res.set_content(oss.str(), "text/plain; charset=utf-8");
              });
}

void WebAPI::start() {
  server_thread_ = std::thread([this]() {
    Logger::Instance().log("WebAPI started");
    server_ready_ = true;

    server_.listen("0.0.0.0", 8080);
    Logger::Instance().log("WebAPI server exited listen()");
  });

  // ensure WebAPI started before returning
  while (!server_ready_) {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
  server_running_ = true;
}

void WebAPI::stop() {
  if (!server_running_) {
    return;
  }

  server_.stop();

  if (server_thread_.joinable()) {
    server_thread_.join();
  }

  server_running_ = false;
  Logger::Instance().log("WebAPI stopped");
}

void WebAPI::publish_sensor_value(double value) {
  {
    std::lock_guard<std::mutex> lock(value_mutex_);
    latest_value_ = value;
  }

  std::ostringstream oss;
  oss << std::fixed << std::setprecision(2)
      << "Publishing value to WebAPI: " << value << " °C";
  Logger::Instance().log(oss.str());
}
