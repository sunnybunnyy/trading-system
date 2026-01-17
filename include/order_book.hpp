#pragma once

#include <algorithm>
#include <vector>
#include "order.hpp"

struct OrderBook {
    std::vector<Order> bids;
    std::vector<Order> asks;

    void sort_books();
};

inline void update_top_of_book(OrderBook& book, double bid_price, int bid_size, double ask_price, int ask_size);