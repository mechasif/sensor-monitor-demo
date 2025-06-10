#include "Logger.hpp"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <sstream>

void Logger::log(const std::string& message) noexcept {
  // Lock to ensure thread-safe output
  std::lock_guard<std::mutex> lock(mutex_);

  // Get current system time
  const auto now = std::chrono::system_clock::now();
  const std::time_t now_c = std::chrono::system_clock::to_time_t(now);

  // Convert to local time (thread-safe)
  std::tm tm_struct;
  localtime_r(&now_c, &tm_struct);

  // Format timestamp + message
  std::ostringstream oss;
  oss << "[" << std::put_time(&tm_struct, "%Y-%m-%d %H:%M:%S") << "] "
      << message << '\n';

  // Print to console
  std::cout << oss.str();
}