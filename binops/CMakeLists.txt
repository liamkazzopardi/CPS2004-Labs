cmake_minimum_required(VERSION 3.5.0)
project(binops VERSION 0.1.0 LANGUAGES C CXX)

add_executable(binops main.cpp)
set(SOURCE_FILES1 struct_binops.cpp)
add_executable(binopsStruct ${SOURCE_FILES1})

