add_library(stack stack.cpp stack.hpp)
add_subdirectory(stack_tests)

set_property(TARGET stack PROPERTY CXX_STANDARD 14)

