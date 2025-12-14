#include "register.h"

#include <stdio.h>
#include <stdint.h>

static inline void print_lld(int64_t x)          { printf("%lld\n", x); }
static inline void print_llu(uint64_t x)         { printf("%llu\n", x); }
static inline void print_s(const char* x)        { printf("%s\n", x); }

#define answer(x) _Generic((x), \
    long long:          print_lld, \
    unsigned long long: print_llu, \
    char*:              print_s, \
    const char*:        print_s  \
)(x)

#define submit_a(x) do { printf("Part A: "); answer(x); } while(0)
#define submit_b(x) do { printf("Part B: "); answer(x); } while(0)

static void part_a(const char* input)
{
    int64_t ans = 42;
    submit_a(ans);
}

static void part_b(const char* input)
{
    const char* ans = "Hello, AoC 2025!";
    submit_b(ans);
}

REGISTER_SOLUTION(
    .year = 2025,
    .day = 1,
    .part_a = part_a,
    .part_b = part_b,
)
