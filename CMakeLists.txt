cmake_minimum_required(VERSION 3.16)
project(DiagnosticsMonitor)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(include)


add_executable(monitor
src/main.cpp
src/Logger.cpp
src/MetricsRegistry.cpp
)