cmake_minimum_required(VERSION 3.6)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

project(ryzhkov_a_p)

include(cmake/build_prefix.cmake)

add_subdirectory(prj.labs)