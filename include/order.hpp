#pragma once

#include <chrono>

using time_point = std::chrono::time_point<std::chrono::steady_clock>;

enum direction {
    BUY,
    SELL,
    NONE
};

struct Order {
    int price;
    int size;
    direction dir;
    time_point timestamp = std::chrono::steady_clock::now();

    Order();
    Order(int price, int size, direction dir);
};