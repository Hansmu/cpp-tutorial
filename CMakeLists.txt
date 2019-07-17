cmake_minimum_required(VERSION 3.14)
project(cpp_tutorial)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_tutorial main.cpp Player.cpp Player.h Enemy.cpp Enemy.h GenericClass.h)