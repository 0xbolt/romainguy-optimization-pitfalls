cmake_minimum_required(VERSION 3.27)
project(RomainguyOptimizationPitfalls)

set(CMAKE_CXX_)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(googletest)
include(GoogleTest)
add_subdirectory(benchmark)

add_executable(
    you_are_going_to_need_it
    you_are_going_to_need_it.cpp
)
target_link_libraries(
    you_are_going_to_need_it
    benchmark::benchmark
)

add_executable(
    the_path_not_taken
    the_path_not_taken.cpp
)
target_link_libraries(
    the_path_not_taken
    benchmark::benchmark
)
