module;

#include <chrono>
#include <iostream>

export module strategy_engine;

import events;
import event_queue;

export class StrategyEngine {
public:
    StrategyEngine(EventQueue<MarketUpdate>& in_queue)
        : in_queue(in_queue) {}

    void run() {
        while (true) {
            MarketUpdate update = in_queue.pop();
            time_point now = std::chrono::steady_clock::now();
            auto latency = now - update.timestamp;

            std::cout << "Strategy received update. Latency(ns): " << latency << std::endl;
        }
    }

private:
    EventQueue<MarketUpdate>& in_queue;
};