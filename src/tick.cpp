#include "tick.hpp"

Tick::Tick(double bid_price, double ask_price, int bid_size, int ask_size, time_point timestamp)
    : bid_price(bid_price),
    ask_price(ask_price),
    bid_size(bid_size),
    ask_size(ask_size),
    timestamp(timestamp)
{}