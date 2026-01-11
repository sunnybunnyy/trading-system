#include <chrono>
#include <iostream>
#include <thread>
#include "market_data_engine.hpp"
#include "order_loader.hpp"

MarketDataEngine::MarketDataEngine(EventQueue<Order> &out_queue)
    : out_queue(out_queue) {}

void MarketDataEngine::run()
{
    using namespace std::chrono_literals;
    std::string path = "data/AAPL.csv";
    std::vector<Order> orders = load_orders(path);
    const double speedup = 10.0;
    time_point start = std::chrono::steady_clock::now();

    for (size_t i = 1; i < orders.size(); ++i)
    {
        const Order &prev = orders[i - 1];
        const Order &curr = orders[i];
        auto duration = (curr.timestamp - prev.timestamp).count();
        auto sleep_duration = static_cast<int64_t>(duration / speedup);
        std::this_thread::sleep_for(std::chrono::nanoseconds{sleep_duration});

        Order update {
            curr.price,
            curr.size,
            curr.dir
        };

        while (!out_queue.push(update))
            ; // spin

        if (i == orders.size() - 1)
        {
            time_point end = std::chrono::steady_clock::now();
            std::cout << orders.size() << " updates in " << (end - start) / 1ms << "ms" << std::endl;
            ;
        }
    }
}