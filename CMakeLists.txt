cmake_minimum_required(VERSION 3.27)
project(stos_i_kolejka)

set(CMAKE_CXX_STANDARD 17)

add_executable(stos_i_kolejka main.cpp
        cmake-build-debug/Queue.cpp
        cmake-build-debug/Queue.h)
