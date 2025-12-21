#include <chrono>
#include <thread>
#include "execution_engine.hpp"

void ExecutionEngine::run() {
    while (true) {
        // TODO: implement order execution
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(1s);
    }
}