#ifndef AOC_INPUT_H
#define AOC_INPUT_H

#include <stddef.h>

// Read entire file into a null-terminated string (caller must free)
char* aoc_read_file(const char* path);

// Read file for a specific day: looks for "inputs/YYYY/dDD.txt"
char* aoc_read_input(int year, int day);

#endif // AOC_INPUT_H
