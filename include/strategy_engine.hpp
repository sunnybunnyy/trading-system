#pragma once

#include "events.hpp"
#include "event_queue.hpp"

class StrategyEngine {
public:
    StrategyEngine(EventQueue<MarketUpdate>& in_queue);
    void run();

private:
    EventQueue<MarketUpdate>& in_queue;
};