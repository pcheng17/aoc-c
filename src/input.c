#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* aoc_read_file(const char* path)
{
    FILE* f = fopen(path, "r");
    if (!f) return NULL;

    fseek(f, 0, SEEK_END);
    uint32_t size = (uint32_t)ftell(f);
    fseek(f, 0, SEEK_SET);

    char* buf = malloc(size + 1);
    if (buf)
    {
        fread(buf, 1, size, f);
        buf[size] = '\0';
    }
    fclose(f);
    return buf;
}

char* aoc_read_input(int year, int day)
{
    char path[32];
    snprintf(path, sizeof(path), "./inputs/%04d/%02d.txt", year, day);
    return aoc_read_file(path);
}
