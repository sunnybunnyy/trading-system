#include "events.hpp"

MarketUpdate::MarketUpdate(std::string ticker, int price, int size, std::string direction)
    : Tick(price, size, direction, std::chrono::steady_clock::now()),
    ticker(ticker)
{}