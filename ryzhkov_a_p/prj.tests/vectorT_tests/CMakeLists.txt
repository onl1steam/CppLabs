add_executable(vectorT_tests testVectorT.cpp)
target_link_libraries(vectorT_tests vectorT)
set_property(TARGET vectorT_tests PROPERTY CXX_STANDARD 14)