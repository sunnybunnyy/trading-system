#pragma once

#include <string>
#include <vector>
#include "tick.hpp"

using Clock = std::chrono::steady_clock;
using TimePoint = std::chrono::time_point<Clock>;

std::vector<Tick> load_ticks(const std::string& path);