add_library(matrix matrix.cpp matrix.hpp)
add_subdirectory(matrix_tests)

set_property(TARGET matrix PROPERTY CXX_STANDARD 14)

