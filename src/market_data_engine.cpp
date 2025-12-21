#include <chrono>
#include <thread>
#include "market_data_engine.hpp"

MarketDataEngine::MarketDataEngine(EventQueue<MarketUpdate>& out_queue)
    : out_queue(out_queue) {}

void MarketDataEngine::run() {
    using namespace std::chrono_literals;
    
    int symbol_id = 1;

    while(true) {
        MarketUpdate update(
            symbol_id,
            100.0,
            100.01,
            500,
            400
        );

        out_queue.push(update);
        std::this_thread::sleep_for(1ms);
    }
}