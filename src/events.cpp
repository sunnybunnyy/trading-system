module;

#include <chrono>

export module events;

export using time_point = std::chrono::time_point<std::chrono::steady_clock>;

export struct MarketUpdate {
    int symbol_id;
    double bid_price;
    double ask_price;
    int bid_size;
    int ask_size;
    time_point timestamp = std::chrono::steady_clock::now();
};