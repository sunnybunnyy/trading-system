cmake_minimum_required(VERSION 4.2.1)
project(trading_system VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Boost REQUIRED)
add_library(lib)
target_sources(lib
  PRIVATE
    src/events.cpp src/market_data_engine.cpp src/strategy_engine.cpp src/execution_engine.cpp src/order_book.cpp src/tick.cpp src/tick_loader.cpp

  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS
      include
    FILES
      include/events.hpp
      include/event_queue.hpp
      include/market_data_engine.hpp
      include/strategy_engine.hpp
      include/execution_engine.hpp
      include/order_book.hpp
      include/tick.hpp
)

add_executable(trading_system main.cpp)

target_link_libraries(trading_system PRIVATE lib)
target_link_libraries(trading_system PRIVATE Boost::headers)