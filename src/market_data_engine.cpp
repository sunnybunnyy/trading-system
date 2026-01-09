#include <chrono>
#include <thread>
#include "market_data_engine.hpp"
#include "tick_loader.hpp"

MarketDataEngine::MarketDataEngine(EventQueue<MarketUpdate>& out_queue)
    : out_queue(out_queue) {}

void MarketDataEngine::run() {
    std::string path = "data/AAPL.csv";
    std::vector<Tick> ticks = load_ticks(path);
    const double speedup = 10.0;

    for (size_t i = 1; i < ticks.size(); ++i) {
        const Tick& prev = ticks[i - 1];
        const Tick& curr = ticks[i];
        auto duration = (curr.timestamp - prev.timestamp).count();
        auto sleep_duration = static_cast<int64_t>(duration / speedup);

        std::this_thread::sleep_for(std::chrono::nanoseconds{sleep_duration});

        int slashPos = path.rfind("/");
        int dotPos = path.find(".");
        std::string ticker = path.substr(slashPos, dotPos - slashPos - 1);
        
        MarketUpdate update{
            ticker,
            curr.price,
            curr.size,
            curr.direction
        };

        while(!out_queue.push(update)); // spin
    }
}