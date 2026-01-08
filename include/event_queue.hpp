#pragma once

#include <boost/lockfree/spsc_queue.hpp>

template <typename T, size_t Capacity>
class EventQueue {
public:
    bool push(const T& item) {
        return queue.push(item);
    }

    bool pop() {
        queue.pop();
    }

private:
    boost::lockfree::spsc_queue< T, boost::lockfree::capacity< Capacity > > queue;
};