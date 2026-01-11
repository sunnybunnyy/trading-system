#include "order.hpp"

Order::Order() : price(0), size(0), dir(NONE) {}

Order::Order(int price, int size, direction dir) : price(price), size(size), dir(dir) {}