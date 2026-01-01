#pragma once

#include "tick.hpp"

struct MarketUpdate : public Tick {
    int symbol_id;
    MarketUpdate(int symbol_id, double bid_price, double ask_price, int bid_size, int ask_size);
};