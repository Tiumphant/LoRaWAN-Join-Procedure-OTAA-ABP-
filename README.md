Diognostics & Monitoring Hooks Framework – Modern C++ (WSL Ubuntu)
A modular Diagnostics & Monitoring Hooks framework implemented using Modern C++ (C++20) and built with CMake on Ubuntu (WSL).
This project demonstrates production-style monitoring architecture including logging, metrics collection, event hooks, and performance timing using modern C++ design patterns.

📌 Project Purpose

This project provides a reusable diagnostics layer that can be embedded into any C++ application to enable:
Structured logging
Runtime metrics collection
Event-driven monitoring hooks
Performance measurement
Thread-safe counters and gauges
Modular monitoring architecture
Suitable for:
System software
Embedded systems
LoRa / IoT stacks
Backend services
Message brokers
Performance instrumentation

🚀 Features

✅ Thread-safe Logger (Singleton)
✅ Counter metrics (atomic monotonic counters)
✅ Gauge metrics (atomic up/down values)
✅ Central Metrics Registry
✅ Event Hook / Callback system (Observer pattern)
✅ RAII Performance Timer
✅ Clean modular folder structure
✅ CMake build system
✅ Ubuntu WSL compatible
✅ Modern C++ patterns
🧱 Folder Structure

diagnostics-monitor/
│
├── CMakeLists.txt
├── README.md
│
├── include/
│   ├── logger/
│   │   └── Logger.hpp
│   │
│   ├── metrics/
│   │   ├── Counter.hpp
│   │   ├── Gauge.hpp
│   │   └── MetricsRegistry.hpp
│   │
│   ├── hooks/
│   │   └── EventHook.hpp
│   │
│   └── diagnostics/
│       └── PerfTimer.hpp
│
├── src/
│   ├── main.cpp
│   ├── Logger.cpp
│   └── MetricsRegistry.cpp
│
└── build/

⚙️ Requirements

Ubuntu (or WSL Ubuntu)
g++ 10 or later
CMake 3.16+
make
Install dependencies:
sudo apt update
sudo apt install build-essential cmake


Verify:

g++ --version
cmake --version

🔨 Build Instructions
From project root:
mkdir build
cd build
cmake ..
make


Build output should show:
[100%] Built target monitor
▶️ Run Application
From build folder:
./monitor
Example output:

[INFO] System start
[INFO] Request processed
[INFO] Request processed
RequestLoop took 2ms
api_calls = 5

🧠 Architecture Overview
Application (main.cpp)
        │
        ▼
Diagnostics Framework
 ├── Logger (Singleton)
 ├── MetricsRegistry
 │    ├── Counter
 │    └── Gauge
 ├── EventHook (Observer)
 └── PerfTimer (RAII)

🔄 Runtime Flow
Event Occurs
   ↓
EventHook.trigger()
   ↓
Callbacks execute
   ↓
Metrics updated + logs written
   ↓
Registry reports metrics

🧩 Module Explanation
Logger

Thread-safe singleton
Mutex-protected output
Central logging interface
Counter

Uses std::atomic
Only increments
Used for totals (requests, errors)
Gauge

Atomic value
Supports increment/decrement/set
Used for current state metrics
MetricsRegistry

Central metrics manager
Lazy metric creation
Smart pointer ownership
EventHook
Observer pattern
Multiple subscribers
Decouples producers and listeners
PerfTimer
RAII scope timer
Measures execution time automatically
Logs duration on destruction
🧵 Thread Safety
Thread safety is achieved using:
std::atomic for metrics
std::mutex for logger writes
Thread-safe static initialization for singletons
No global mutable state without protection.

🏗 Design Patterns Used
Pattern	Usage
Singleton	Logger, MetricsRegistry
Observer	EventHook
RAII	PerfTimer
Registry	MetricsRegistry
Atomic	Counter, Gauge
📈 Agile Sprint Breakdown
Sprint 1 — Environment Setup

WSL Ubuntu setup

Compiler & CMake install
Base project structure
Sprint 2 — Logger Module
Thread-safe singleton logger
Structured logging
Sprint 3 — Metrics Core
Counter + Gauge
Atomic thread-safe metrics

Sprint 4 — Metrics Registry
Central metric storage
Lazy creation
Sprint 5 — Hook System
EventHook implementation
Callback subscription

Sprint 6 — Diagnostics
RAII performance timer
Execution timing

Sprint 7 — Integration
Wire all modules

End-to-end demo

🧪 Example Use Cases

API call counting
Performance timing
Health diagnostics
Embedded telemetry
Queue depth monitoring
Signal monitoring
Device metrics

🛠 Extension Ideas
You can extend this framework with:
Prometheus exporter
JSON metrics endpoint
Async logging thread
Syslog adapter
Health check plugins
Thread pool metrics
GoogleTest unit tests
epoll event monitoring
Embedded HAL integration

🧯 Common Build Errors
Header Not Found
Ensure headers are inside include/ subfolders:
include/metrics/MetricsRegistry.hpp
Include must match exactly:

#include "metrics/MetricsRegistry.hpp"
Linux is case-sensitive:
metrics ≠ Metrics
Clean Rebuild
If CMake cache is stale:

cd build
rm -rf *
cmake ..
make

📚 Learning Outcomes

This project teaches:
Modern C++ architecture
CMake project setup
Thread-safe design
RAII usage
Observer pattern
Metrics system design
Modular diagnostics framework
