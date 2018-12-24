add_executable(stack_tests testStack.cpp)
target_link_libraries(stack_tests stack)
set_property(TARGET stack_tests PROPERTY CXX_STANDARD 14)