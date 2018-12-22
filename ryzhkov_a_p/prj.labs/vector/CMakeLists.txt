add_library(vector vector.cpp vector.h)
add_subdirectory(vector_tests)

set_property(TARGET vector PROPERTY CXX_STANDARD 14)

