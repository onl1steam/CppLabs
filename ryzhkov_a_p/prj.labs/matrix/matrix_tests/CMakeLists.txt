add_executable(matrix_tests testMatrix.cpp)
target_link_libraries(matrix_tests matrix)
set_property(TARGET matrix_tests PROPERTY CXX_STANDARD 14)