#include "metrics/MetricsRegistry.hpp"
#include <iostream>


MetricsRegistry& MetricsRegistry::instance() {
static MetricsRegistry inst;
return inst;
}


Counter& MetricsRegistry::getCounter(const std::string& name) {
if (!counters[name]) {
counters[name] = std::make_unique<Counter>();
}
return *counters[name];
}


void MetricsRegistry::report() {
for (auto& [k,v] : counters) {
std::cout << k << " = " << v->get() << std::endl;
}
}