cmake_minimum_required(VERSION 3.28.3)
project(trading_system VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)
add_executable(trading_system main.cpp)

target_link_libraries(trading_system PUBLIC events)
