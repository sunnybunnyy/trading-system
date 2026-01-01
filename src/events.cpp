#include "events.hpp"

MarketUpdate::MarketUpdate(int symbol_id, double bid_price, double ask_price, int bid_size, int ask_size)
    : Tick(bid_price, ask_price, bid_size, ask_size, std::chrono::steady_clock::now()),
    symbol_id(symbol_id)
{}