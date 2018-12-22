add_library(queue queue.cpp queue.hpp)
add_subdirectory(queue_tests)

set_property(TARGET queue PROPERTY CXX_STANDARD 14)

