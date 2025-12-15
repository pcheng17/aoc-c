#include "print.h"
#include "register.h"
#include "stdlib.h"

static void solve(const char* input)
{
    int dial = 50;
    int part_a = 0;
    int part_b = 0;

    const char* p = input;
    while (*p) {
        int8_t dir = (*p == 'R');
        ++p;

        int amount = 0;
        while (*p >= '0' && *p <= '9') {
            amount = amount * 10 + (*p - '0');
            ++p;
        }

        // Skip newline
        ++p;

        if (dir) {
            dial += amount;
            part_b += (dial) / 100;
            dial %= 100;
        } else {
            int reversed = (100 - dial) % 100;
            dial = reversed + amount;
            part_b += (dial) / 100;
            dial = (100 - dial % 100) % 100;
        }
        part_a += (dial == 0);
    }

    print_a(part_a);
    print_b(part_b);
}

REGISTER_SOLUTION(.year = 2025, .day = 1, .solve = solve)
