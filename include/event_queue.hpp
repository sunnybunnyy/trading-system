#pragma once

#include <boost/lockfree/spsc_queue.hpp>

template <typename T>
class EventQueue {
using SPSC_queue = boost::lockfree::spsc_queue< T, boost::lockfree::capacity< (1 << 20) > >;
public:
    EventQueue() : queue(std::make_unique<SPSC_queue>()) {}
    bool push(const T& item) {
        return queue->push(item);
    }

    bool pop(T& item) {
        return queue->pop(item);
    }

private:
    std::unique_ptr<SPSC_queue> queue;
};