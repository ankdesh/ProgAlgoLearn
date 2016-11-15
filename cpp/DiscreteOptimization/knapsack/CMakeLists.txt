cmake_minimum_required (VERSION 2.6)

add_compile_options(-std=c++11)
project (Knapsack)
add_executable(Knapsack driver.cpp knapsackBrute.cpp)
