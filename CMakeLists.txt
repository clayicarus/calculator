cmake_minimum_required(VERSION 3.23)
project(calculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(calculator main.cpp Calculator.cpp Calculator.h Postfix.cpp Postfix.h Result.cpp Result.h Tool.cpp Tool.h)
