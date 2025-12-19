module;

#include <queue>
#include <mutex>
#include <condition_variable>

export module event_queue;

export template <typename T>
class EventQueue {
public:
    void push(const T& item) {
        {
            std::lock_guard<std::mutex> lock(mutex);
            queue.push(item);
        }
        cv.notify_one();
    }

    T pop() {
        std::unique_lock<std::mutex> lock(mutex);
        cv.wait(lock, [this]() { 
            return !queue.empty();
        });

        T item = queue.front();
        queue.pop();
        return item;
    }

private:
    std::queue<T> queue;
    std::mutex mutex;
    std::condition_variable cv;
};