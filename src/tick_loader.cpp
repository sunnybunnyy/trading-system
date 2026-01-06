#include "tick.hpp"
#include <fstream>
#include <cmath>
#include <chrono>

using Clock = std::chrono::steady_clock;
using TimePoint = std::chrono::time_point<Clock>;

std::vector<Tick> load_ticks(const std::string& path) {
    std::vector<Tick> ticks;
    std::ifstream file(path);
    std::string line;

    while (getline(file, line)) {
        std::istringstream s(line);
        std::string field;
        Tick t;

        getline(s, field, ',');
        float seconds = stof(field);
        int nanoseconds = static_cast<int>(seconds*pow(10, 9));
        const Clock::duration duration = std::chrono::nanoseconds(nanoseconds);
        const TimePoint timestamp(duration);
        t.timestamp = timestamp;

        getline(s, field, ',');
        if (field == "1") {
            getline(s, field, ','); // discard order ID

            getline(s, field, ',');
            t.size = std::stoi(field);
            
            getline(s, field, ',');
            t.price = std::stoi(field);

            getline(s, field, ',');
            if (field == "1") {
                t.direction = "buy";
            } else if (field == "-1") {
                t.direction = "sell";
            }

            ticks.emplace_back(t);
        }
    }

    return ticks;
}