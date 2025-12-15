#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "input.h"
#include "solution.h"

#ifdef __APPLE__
#include <mach-o/getsect.h>
#include <mach-o/ldsyms.h>
#endif

int main(int argc, char** argv)
{
    const int run_all = argc == 1;
    const int target_year = run_all ? -1 : atoi(argv[1]);
    const int target_day = run_all ? -1 : atoi(argv[2]);

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

    struct timespec ts_start, ts_end;

    double total_elapsed_ms = 0.0;
    int32_t solved_count = 0;

    for (const AoCSolution** s = start; s < stop; ++s)
    {
        const AoCSolution* sol = *s;
        if (run_all || (sol->year == target_year && sol->day == target_day))
        {
            printf("---- %04d, Day %02d  ----\n", sol->year, sol->day);

            char* input = aoc_read_input(sol->year, sol->day);
            if (!input)
            {
                fprintf(stderr, "Failed to read input\n");
                continue;
            }

            clock_gettime(CLOCK_MONOTONIC, &ts_start);
            sol->solve(input);
            clock_gettime(CLOCK_MONOTONIC, &ts_end);
            double elapsed_ms = (double)(ts_end.tv_sec - ts_start.tv_sec) * 1000.0 +
                                (double)(ts_end.tv_nsec - ts_start.tv_nsec) / 1000000.0;
            total_elapsed_ms += elapsed_ms;

            free(input);
            ++solved_count;
        }
    }

    printf("\n------- Summary -------\n");
    printf("Ran %d solution(s)\n", solved_count);
    printf("Total elapsed time: %.3f ms\n", total_elapsed_ms);

    return 0;
}
