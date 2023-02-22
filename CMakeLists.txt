cmake_minimum_required(VERSION 3.23)
project(khf01)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra -pedantic")

add_executable(khf01 main.cpp Ital.h Raktar.h)
