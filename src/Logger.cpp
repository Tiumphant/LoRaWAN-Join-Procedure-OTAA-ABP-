
#include "logger/Logger.hpp"


Logger& Logger::instance() {
static Logger inst; // thread-safe (C++11+)
return inst;
}


void Logger::info(const std::string& msg) {
std::lock_guard<std::mutex> lock(mtx);
std::cout << "[INFO] " << msg << std::endl;
}


void Logger::error(const std::string& msg) {
std::lock_guard<std::mutex> lock(mtx);
std::cerr << "[ERROR] " << msg << std::endl;
}