#pragma once

#include "event_queue.hpp"
#include "order.hpp"

class StrategyEngine {
public:
    StrategyEngine(EventQueue<Order>& in_queue);
    void run();

private:
    EventQueue<Order>& in_queue;
};