#include "order_book.hpp"

void OrderBook::sort_books() {
    std::sort(bids.begin(), bids.end(),
        [](const PriceLevel& a, const PriceLevel& b)
        {
            return a.price > b.price;
        });

    std::sort(asks.begin(), asks.end(),
        [](const PriceLevel& a, const PriceLevel& b)
        {
            return a.price < b.price;
        });
}