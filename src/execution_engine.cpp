module;

#include <chrono>
#include <thread>

export module ExecutionEngine;

class ExecutionEngine {
public:
    void run() {
        while (true) {
            // TODO: implement order execution
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(1s);
        }
    }
}