#pragma once
#include <atomic>


class Counter {
std::atomic<long> value{0};


public:
void increment() { value++; }
long get() const { return value.load(); }
};