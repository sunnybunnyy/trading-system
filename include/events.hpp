#pragma once

#include "tick.hpp"

struct MarketUpdate : public Tick {
    std::string ticker;
    MarketUpdate();
    MarketUpdate(std::string ticker, int price, int size, std::string direction);
};