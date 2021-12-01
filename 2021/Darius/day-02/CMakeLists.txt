cmake_minimum_required(VERSION 3.20)

add_executable(day-02 solution.cpp)
configure_file(input.txt ${CMAKE_CURRENT_BINARY_DIR}/input.txt)