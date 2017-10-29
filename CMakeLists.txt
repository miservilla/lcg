cmake_minimum_required(VERSION 3.8)
project(lcg)

set(CMAKE_C_STANDARD 90)

set(SOURCE_FILES main.c)
add_executable(lcg ${SOURCE_FILES})