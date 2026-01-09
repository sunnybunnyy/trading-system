#include "events.hpp"

MarketUpdate::MarketUpdate()
    : Tick(0, 0, "f", std::chrono::steady_clock::now()),
    ticker("")
    {}
MarketUpdate::MarketUpdate(std::string ticker, int price, int size, std::string direction)
    : Tick(price, size, direction, std::chrono::steady_clock::now()),
    ticker(ticker)
    {}