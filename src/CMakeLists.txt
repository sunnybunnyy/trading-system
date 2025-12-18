add_library(events events.cpp event_queue.cpp)
target_compile_options(events PRIVATE -fmodules-ts)