#include "events.hpp"

MarketUpdate::MarketUpdate(int symbol_id, double bid_price, double ask_price, int bid_size, int ask_size)
    : symbol_id(symbol_id),
    bid_price(bid_price),
    ask_price(ask_price),
    bid_size(bid_size),
    ask_size(ask_size),
    timestamp(std::chrono::steady_clock::now())
{}