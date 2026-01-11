#pragma once

#include "order.hpp"
#include "event_queue.hpp"

class MarketDataEngine {
public:
    MarketDataEngine(EventQueue<Order>& out_queue);
    void run();

private:
    EventQueue<Order>& out_queue;
};