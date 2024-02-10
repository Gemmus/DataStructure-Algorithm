cmake_minimum_required(VERSION 3.25)
project(Cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(Cpp main.cpp fft.cpp)

set_target_properties(Cpp PROPERTIES LINK_FLAGS -Wl,--stack,10000000)
