#ifndef AOC_SOLUTION_H
#define AOC_SOLUTION_H

#include <stdint.h>

typedef struct {
    int16_t year;
    int8_t day;
    void (*solve)(const char* input);
} AoCSolution;

#endif // AOC_SOLUTION_H
