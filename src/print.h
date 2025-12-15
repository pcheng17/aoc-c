#pragma once

#include <stdio.h>
#include <stdint.h>

// clang-format off
static inline void print_lld(int64_t x)   { printf("%lld\n", x); }
static inline void print_llu(uint64_t x)  { printf("%llu\n", x); }
static inline void print_int(int x)       { printf("%d\n", x); }
static inline void print_s(const char* x) { printf("%s\n", x); }

#define answer(x) _Generic((x),    \
    long long:          print_lld, \
    unsigned long long: print_llu, \
    int:                print_int, \
    char*:              print_s,   \
    const char*:        print_s    \
)(x)

#define print_a(x) do { printf("  Part A: "); answer(x); } while(0)
#define print_b(x) do { printf("  Part B: "); answer(x); } while(0)
// clang-format on
