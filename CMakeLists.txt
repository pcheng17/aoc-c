cmake_minimum_required(VERSION 3.20)

project(aoc LANGUAGES C)

# ---- Configuration ----

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Enable useful warnings
if (CMAKE_C_COMPILER_ID MATCHES "Clang|GNU")
    add_compile_options(
        -Wall
        -Wextra
        -Wpedantic
        -Wshadow
        -Wconversion
        -Wno-unused-parameter
    )
endif()

# ---- Source Collection ----

file(GLOB_RECURSE AOC_SOURCES
    src/*.c
)

add_executable(aoc ${AOC_SOURCES})

target_include_directories(aoc PRIVATE
    src
)

# ---- Linker Section Safety ----
# Prevent dead-stripping of the custom section
# (important for --gc-sections / LTO)

if (CMAKE_C_COMPILER_ID MATCHES "Clang|GNU" AND NOT APPLE)
    target_link_options(aoc PRIVATE
        -Wl,--undefined=__start_aoc_solutions
    )
endif()

# ---- Build Types ----

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
endif()

# ---- Optional Sanitizers ----

option(AOC_SANITIZE "Enable address/undefined sanitizers" OFF)

if (AOC_SANITIZE AND CMAKE_C_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(aoc PRIVATE
        -fsanitize=address,undefined
        -fno-omit-frame-pointer
    )
    target_link_options(aoc PRIVATE
        -fsanitize=address,undefined
    )
endif()
