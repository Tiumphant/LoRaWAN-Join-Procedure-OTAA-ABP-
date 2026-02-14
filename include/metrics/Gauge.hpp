#pragma once
#include <atomic>

class Gauge {
    std::atomic<long> value{0};

public:
    Gauge() = default;
    explicit Gauge(long v) : value(v) {}

    void set(long v) {
        value.store(v, std::memory_order_relaxed);
    }

    void increment(long v = 1) {
        value.fetch_add(v, std::memory_order_relaxed);
    }

    void decrement(long v = 1) {
        value.fetch_sub(v, std::memory_order_relaxed);
    }

    long get() const {
        return value.load(std::memory_order_relaxed);
    }
};
