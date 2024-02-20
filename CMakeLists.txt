cmake_minimum_required(VERSION 3.27)
project(dust_sql C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)
include_directories(src)

add_executable(dust_sql
        src/main.c
        src/parse.c
        src/start.c
        src/readcom.c)
