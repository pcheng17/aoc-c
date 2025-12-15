#include "print.h"
#include "register.h"
#include "stdlib.h"

int compare(const void* a, const void* b)
{
    int32_t x = *(int32_t*)a;
    int32_t y = *(int32_t*)b;
    return (x > y) - (x < y);
}

static void solve(const char* input)
{
    // I know there are 1000 lines in the input
    const uint32_t lines = 1000;

    size_t sz = sizeof(int32_t) * lines;
    size_t aligned_sz = (sz + 31) & ~(size_t)31;
    int32_t* left = aligned_alloc(32, aligned_sz);
    int32_t* right = aligned_alloc(32, aligned_sz);
    printf("Lines: %d\n", lines);

    // Parse the input integers into left and right arrays
    const char* p = input;
    int idx = 0;
    while (*p) {
        int32_t l = 0;
        while (*p >= '0' && *p <= '9') {
            l = l * 10 + (int)(*p - '0');
            ++p;
        }

        // Move past the white space
        p += 3;

        int32_t r = 0;
        while (*p >= '0' && *p <= '9') {
            r = r * 10 + (int)(*p - '0');
            ++p;
        }

        ++p; // Move past the newline

        left[idx] = l;
        right[idx] = r;
        ++idx;
    }

    // Sort left and right arrays using standdard integer comparisoin
    qsort(left, lines, sizeof(int32_t), compare);
    qsort(right, lines, sizeof(int32_t), compare);

    int32_t part_a = 0;
    for (uint32_t i = 0; i < lines; ++i) {
        part_a += abs(left[i] - right[i]);
    }

    print_a(part_a);
    print_b("Not implemented");

    free(left);
    free(right);
}

REGISTER_SOLUTION(.year = 2024, .day = 1, .solve = solve)
