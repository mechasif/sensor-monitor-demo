#include <atomic>
#include <csignal>
#include <iostream>

#include "Logger.hpp"
#include "Monitor.hpp"

namespace {
std::atomic<bool> running_flag{true};
}

void signal_handler([[maybe_unused]] int signal) noexcept {
  Logger::Instance().log("Signal received, shutting down...");
  running_flag = false;
}

int main() {
  // Register signal handlers
  // Ctrl+C
  std::signal(SIGINT, signal_handler);
  // kill or systemd stop
  std::signal(SIGTERM, signal_handler);

  Monitor monitor;

  // Start monitoring loop
  monitor.run(running_flag);

  Logger::Instance().log("Application exited cleanly.");
  std::cout << std::flush;

  return 0;
}