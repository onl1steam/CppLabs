add_library(complex complex.hpp complex.cpp)
add_subdirectory(complex_tests)


set_property(TARGET complex PROPERTY CXX_STANDARD 14)

