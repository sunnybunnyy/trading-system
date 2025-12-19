add_library(events events.cpp event_queue.cpp market_data_engine.cpp strategy_engine.cpp)
target_compile_options(events PRIVATE -fmodules-ts)