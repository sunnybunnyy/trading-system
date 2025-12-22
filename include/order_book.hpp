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

inline void update_top_of_book(OrderBook& book, double bid_price, int bid_size, double ask_price, int ask_size);