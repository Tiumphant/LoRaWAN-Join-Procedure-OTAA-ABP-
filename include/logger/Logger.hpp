#pragma once
#include <iostream>
#include <mutex>
#include <chrono>
#include <iomanip>


class Logger {
public:
static Logger& instance();


void info(const std::string& msg);
void error(const std::string& msg);


private:
std::mutex mtx;
Logger() = default;
};