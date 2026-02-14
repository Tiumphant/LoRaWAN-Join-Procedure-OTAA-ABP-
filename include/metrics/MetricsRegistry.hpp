#pragma once
#include <unordered_map>
#include <memory>
#include <string>
#include "Counter.hpp"


class MetricsRegistry {
public:
static MetricsRegistry& instance();


Counter& getCounter(const std::string& name);
void report();


private:
std::unordered_map<std::string, std::unique_ptr<Counter>> counters;
};