#pragma once
#include "solution.h"

#define CONCAT_(a, b) a##b
#define CONCAT(a, b) CONCAT_(a, b)

#ifdef __APPLE__
#define REGISTER_SOLUTION(...)                                             \
    static const AoCSolution CONCAT(__aoc_sol_, __LINE__) = {__VA_ARGS__}; \
    static const AoCSolution* CONCAT(__aoc_ptr_, __LINE__)                 \
        __attribute__((used, section("__DATA,aoc_solutions"))) = &CONCAT(__aoc_sol_, __LINE__);
#else
#define REGISTER_SOLUTION(...)                                             \
    static const AoCSolution CONCAT(__aoc_sol_, __LINE__) = {__VA_ARGS__}; \
    static const AoCSolution* CONCAT(__aoc_ptr_, __LINE__)                 \
        __attribute__((used, section("aoc_solutions"))) = &CONCAT(__aoc_sol_, __LINE__);
#endif
