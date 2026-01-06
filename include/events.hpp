#pragma once

#include "tick.hpp"

struct MarketUpdate : public Tick {
    int symbol_id;
    MarketUpdate(int symbol_id, int price, int size, std::string direction);
};