#pragma once

#include <chrono>

using time_point = std::chrono::time_point<std::chrono::steady_clock>;

struct Tick {
    double bid_price;
    double ask_price;
    int bid_size;
    int ask_size;
    time_point timestamp;

    Tick(double bid_price, double ask_price, int bid_size, int ask_size, time_point timestamp);
};

struct MarketUpdate : public Tick {
    int symbol_id;
    MarketUpdate(int symbol_id, double bid_price, double ask_price, int bid_size, int ask_size);
};