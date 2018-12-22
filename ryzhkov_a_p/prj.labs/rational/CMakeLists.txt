add_library(rational rational.cpp rational.hpp)
add_subdirectory(rational_tests)

set_property(TARGET rational PROPERTY CXX_STANDARD 14)

