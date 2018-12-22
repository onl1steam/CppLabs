add_library(priority_queue priority_queue.h priority_queue.cpp)
add_subdirectory(priority_queue_tests)


set_property(TARGET complex PROPERTY CXX_STANDARD 14)

