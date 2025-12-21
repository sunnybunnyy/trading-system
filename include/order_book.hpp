#pragma once

#include <algorithm>
#include <vector>

struct PriceLevel {
    double price;
    int size;
};

struct OrderBook {
    std::vector<PriceLevel> bids;
    std::vector<PriceLevel> asks;

    void sort_books();
};