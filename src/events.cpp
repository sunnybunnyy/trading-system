#include "events.hpp"

MarketUpdate::MarketUpdate(int symbol_id, int price, int size, std::string direction)
    : Tick(price, size, direction, std::chrono::steady_clock::now()),
    symbol_id(symbol_id)
{}