cmake_minimum_required(VERSION 3.5)

project(Queue)

option(Mode "Mode" LIB)
set(CMAKE_SHARED_LIBRARY_PREFIX "")

add_library(matrix SHARED ./src/matrix.c)

if (Mode) 
add_executable(test ./tests/autotests.c ./tests/run_test.c)
target_link_libraries(test matrix)
endif()