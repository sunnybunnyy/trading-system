#pragma once

#include <chrono>

using time_point = std::chrono::time_point<std::chrono::steady_clock>;

struct MarketUpdate {
    int symbol_id;
    double bid_price;
    double ask_price;
    int bid_size;
    int ask_size;
    time_point timestamp;

    MarketUpdate(int symbol_id, double bid_price, double ask_price, int bid_size, int ask_size);
};