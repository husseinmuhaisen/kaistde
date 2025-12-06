cmake_minimum_required(VERSION 3.27)

project(kaistruct-demo C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(
    niessuh
    kaistde_write.c
    make_format.c
)

target_include_directories(
    niessuh PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../inc
)

target_compile_options(
    niessuh PRIVATE
    -Wall -Wextra -O2
)
