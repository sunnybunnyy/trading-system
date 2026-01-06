#pragma once

#include <chrono>

using time_point = std::chrono::time_point<std::chrono::steady_clock>;

struct Tick {
    int price;
    int size;
    std::string direction;
    time_point timestamp;

    Tick();
    Tick(int price, int size, std::string direction, time_point timestamp);
};