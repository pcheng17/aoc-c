#include "print.h"
#include "register.h"
#include "stdlib.h"

static void solve(const char* input)
{
    int part_a = 0;
    int part_b = 0;

    const char* p = input;
    while (*p) {
        uint64_t range_start, range_end;
        while (*p >= '0' && *p <= '9') {
            range_start = range_start * 10 + (uint64_t)(*p - '0');
            ++p;
        }

        ++p; // Move past the `-`

        while (*p >= '0' && *p <= '9') {
            range_end = range_end * 10 + (uint64_t)(*p - '0');
            ++p;
        }

        ++p; // Move past the comma

    }

    print_a("Not implemented");
    print_b("Not implemented");
}

REGISTER_SOLUTION(.year = 2025, .day = 2, .solve = solve)
