#include "logger/Logger.hpp"
#include "metrics/MetricsRegistry.hpp"
#include "hooks/EventHook.hpp"
#include "diagnostics/PerfTimer.hpp"

int main() {

    Logger::instance().info("System start");

    auto& registry = MetricsRegistry::instance();
    auto& apiCalls = registry.getCounter("api_calls");

    EventHook onRequest;

    onRequest.subscribe([&]() {
        apiCalls.increment();
        Logger::instance().info("Request processed");
    });

    {
        PerfTimer timer("RequestLoop");
        for(int i=0;i<5;i++) {
            onRequest.trigger();
        }
    }

    registry.report();
}
