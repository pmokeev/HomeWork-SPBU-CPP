cmake_minimum_required(VERSION 3.20)
project(homework03_12)

set(PROJECT_SOURCES BinaryTree.hpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(homework03_12 main.cpp ${PROJECT_SOURCES})
