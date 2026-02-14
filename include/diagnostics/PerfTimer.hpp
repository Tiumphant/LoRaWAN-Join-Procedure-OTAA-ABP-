#pragma once
#include <chrono>
#include <string>
#include "logger/Logger.hpp"

class PerfTimer {
    std::string name;
    std::chrono::steady_clock::time_point start;

public:
    PerfTimer(std::string n)
        : name(std::move(n)), start(std::chrono::steady_clock::now()) {}

    ~PerfTimer() {
        auto end = std::chrono::steady_clock::now();
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
        Logger::instance().info(name + " took " + std::to_string(ms.count()) + "ms");
    }
};
