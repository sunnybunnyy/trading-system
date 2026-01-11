#include <chrono>
#include <cmath>
#include <fstream>
#include "order_loader.hpp"

std::vector<Order> load_orders(const std::string &path)
{
    std::vector<Order> orders;
    std::ifstream file(path);
    std::string line;

    while (getline(file, line))
    {
        std::istringstream s(line);
        std::string field;
        Order t;

        getline(s, field, ',');
        float seconds = stof(field);
        int nanoseconds = static_cast<int>(seconds * pow(10, 9));
        const Clock::duration duration = std::chrono::nanoseconds(nanoseconds);
        const TimePoint timestamp(duration);
        t.timestamp = timestamp;

        getline(s, field, ',');
        if (field == "1")
        {
            getline(s, field, ','); // discard order ID

            getline(s, field, ',');
            t.size = std::stoi(field);

            getline(s, field, ',');
            t.price = std::stoi(field);

            getline(s, field, ',');
            if (field == "1")
            {
                t.dir = BUY;
            }
            else if (field == "-1")
            {
                t.dir = SELL;
            }

            orders.emplace_back(t);
        }
    }

    return orders;
}