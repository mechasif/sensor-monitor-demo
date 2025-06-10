#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <mutex>
#include <string>

class Logger {
 public:
  // Singleton pattern
  static Logger& Instance() noexcept {
    static Logger instance;
    return instance;
  }

  void log(const std::string& message) noexcept;

 private:
  Logger() noexcept = default;
  ~Logger() noexcept = default;

  Logger(const Logger&) = delete;
  Logger& operator=(const Logger&) = delete;
  Logger(Logger&&) = delete;
  Logger& operator=(Logger&&) = delete;

  std::mutex mutex_{};
};

#endif