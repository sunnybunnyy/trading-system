#include "tick.hpp"

Tick::Tick() : price(0), size(0), direction(""), timestamp(std::chrono::steady_clock::now()) {}

Tick::Tick(int price, int size, std::string direction, time_point timestamp)
    : price(price),
    size(size),
    direction(direction),
    timestamp(timestamp)
{}