#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "solution.h"

#ifdef __APPLE__
#include <mach-o/getsect.h>
#include <mach-o/ldsyms.h>
#endif

int main(int argc, char** argv)
{
    int run_all = argc == 1;
    int target = run_all ? -1 : atoi(argv[1]);

#ifdef __APPLE__
    unsigned long size = 0;
    const AoCSolution** start =
        (const AoCSolution**)getsectiondata(&_mh_execute_header, "__DATA", "aoc_solutions", &size);
    const AoCSolution** stop = start + (size / sizeof(AoCSolution*));
#else
    extern const AoCSolution* __start_aoc_solutions[];
    extern const AoCSolution* __stop_aoc_solutions[];
    const AoCSolution** start = __start_aoc_solutions;
    const AoCSolution** stop = __stop_aoc_solutions;
#endif

    for (const AoCSolution** s = start; s < stop; ++s)
    {
        const AoCSolution* sol = *s;
        if (run_all || sol->day == target)
        {
            printf("---- %04d, Day %02d  ----\n", sol->year, sol->day);

            char* input = aoc_read_input(sol->year, sol->day);
            if (!input)
            {
                fprintf(stderr, "Failed to read input\n");
                continue;
            }

            sol->part_a(input);
            sol->part_b(input);

            free(input);
        }
    }
}
