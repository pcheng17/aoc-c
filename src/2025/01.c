#include "print.h"
#include "register.h"

static void part_a(const char* input)
{
    int64_t ans = 42;
    print_a(ans);
}

static void part_b(const char* input)
{
    const char* ans = "Hello, AoC 2025!";
    print_b(ans);
}

REGISTER_SOLUTION(
    .year = 2025,
    .day = 1,
    .part_a = part_a,
    .part_b = part_b,
)
