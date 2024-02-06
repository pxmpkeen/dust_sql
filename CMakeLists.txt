cmake_minimum_required(VERSION 3.27)
project(dust_sql C)

set(CMAKE_C_STANDARD 11)

include_directories(res/includes)
include_directories(res/src)

add_executable(dust_sql
        res/src/main.c
        res/src/parse.c
        res/src/start.c)
