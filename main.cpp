#include "execution_engine.hpp"
#include "market_data_engine.hpp"
#include "strategy_engine.hpp"
#include <thread>

int main(int, char**) {
    EventQueue<Order> market_to_strategy;

    MarketDataEngine market(market_to_strategy);
    StrategyEngine strategy(market_to_strategy);
    ExecutionEngine execution;

    std::thread market_thread(&MarketDataEngine::run, &market);
    std::thread strategy_thread(&StrategyEngine::run, &strategy);
    std::thread execution_thread(&ExecutionEngine::run, &execution);

    market_thread.join();
    strategy_thread.join();
    execution_thread.join();
}
