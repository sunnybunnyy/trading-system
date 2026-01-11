#pragma once

#include <string>
#include <vector>
#include "order.hpp"

using Clock = std::chrono::steady_clock;
using TimePoint = std::chrono::time_point<Clock>;

std::vector<Order> load_orders(const std::string &path);