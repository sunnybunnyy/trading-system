#include "order_book.hpp"

void OrderBook::sort_books() {
    std::sort(bids.begin(), bids.end(),
        [](const Order& a, const Order& b)
        {
            return a.price > b.price;
        });

    std::sort(asks.begin(), asks.end(),
        [](const Order& a, const Order& b)
        {
            return a.price < b.price;
        });
}

inline void update_top_of_book(OrderBook& book, double bid_price, int bid_size, double ask_price, int ask_size) {
    book.bids.clear();
    book.asks.clear();
    
    book.bids.emplace_back(bid_price, bid_size);
    book.asks.emplace_back(ask_price, ask_size);
}