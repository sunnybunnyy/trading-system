#include <chrono>
#include <iostream>
#include "strategy_engine.hpp"

StrategyEngine::StrategyEngine(EventQueue<Order>& in_queue)
    : in_queue(in_queue) {}

void StrategyEngine::run() {
    while (true) {
        Order update;
        while(!in_queue.pop(update)); // spin
        time_point now = std::chrono::steady_clock::now();
        auto latency = now - update.timestamp;

        //std::cout << "Strategy received update. Latency(ns): " << latency << std::endl;
    }
}