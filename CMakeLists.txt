cmake_minimum_required(VERSION 3.21)
project(lossless_compression)

set(CMAKE_CXX_STANDARD 14)

add_executable(lossless_compression main.cpp Compress.cpp Compress.h)
