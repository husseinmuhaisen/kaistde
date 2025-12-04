cmake_minimum_required(VERSION 3.27)

project(kaistruct-demo C)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED 23)

add_executable(
    niessuh kaistde_write.c make_format.c
    )

target_compile_options(
    niessuh PRIVATE -Wall -O2
)




