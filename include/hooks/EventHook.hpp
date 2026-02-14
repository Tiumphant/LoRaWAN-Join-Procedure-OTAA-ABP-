#pragma once
#include <functional>
#include <vector>


class EventHook {
std::vector<std::function<void()>> listeners;


public:
void subscribe(std::function<void()> fn) {
listeners.push_back(fn);
}


void trigger() {
for (auto& fn : listeners)
fn();
}
};