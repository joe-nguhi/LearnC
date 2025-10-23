cmake_minimum_required(VERSION 3.22)
project(LearnC C)

# Use modern C standard everywhere
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Optional: warnings and safety flags
add_compile_options(-Wall -Wextra -Wpedantic)

# Add every sub-folder as its own mini project
add_subdirectory(Enums)
add_subdirectory(Unions)
add_subdirectory(StackHeap)
add_subdirectory(Pointers)
