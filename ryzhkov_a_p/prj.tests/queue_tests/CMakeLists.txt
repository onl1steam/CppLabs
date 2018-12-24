add_executable(queue_tests testQueue.cpp)
target_link_libraries(queue_tests queue)
set_property(TARGET queue_tests PROPERTY CXX_STANDARD 14)