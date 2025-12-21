#pragma once

#include "events.hpp"
#include "event_queue.hpp"

class MarketDataEngine {
public:
    MarketDataEngine(EventQueue<MarketUpdate>& out_queue);
    void run();

private:
    EventQueue<MarketUpdate>& out_queue;
};