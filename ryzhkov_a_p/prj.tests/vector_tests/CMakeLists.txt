add_executable(vector_tests testVector.cpp)
target_link_libraries(vector_tests vector)
set_property(TARGET vector_tests PROPERTY CXX_STANDARD 14)