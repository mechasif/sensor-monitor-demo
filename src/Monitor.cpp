#include "Monitor.hpp"

#include <chrono>
#include <iomanip>
#include <sstream>
#include <thread>

#include "Logger.hpp"

void Monitor::run(const std::atomic<bool>& running_flag) {
  Logger::Instance().log("Monitor is running...");
  webapi_.start();

  while (running_flag.load()) {
    double temp = sensor_.read_value();

    // Format message using stringstream
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << "Sensor reading: " << temp
        << " °C";

    Logger::Instance().log(oss.str());
    webapi_.publish_sensor_value(temp);

    // Simulate periodic reading
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  webapi_.stop();
  Logger::Instance().log("Monitor stopped.");
}