cmake_minimum_required(VERSION 3.16.3)
project(calculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(calculator main.cpp Calculator.cpp Calculator.h Postfix/Postfix.cpp Postfix/Postfix.h Result.cpp Result.h Postfix/Tool.cpp Postfix/Tool.h Postfix/PostFunc.cpp Postfix/PostFunc.h)
