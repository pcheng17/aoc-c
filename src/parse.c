#include <stddef.h>
#include <stdlib.h>

char** aoc_split_lines(const char* input, size_t* count)
{
    if (!input || !count) return NULL;

    size_t n = 0;
    const char* ptr = input;
    while (*ptr)
    {
        if (*ptr == '\n') n++;
        ptr++;
    }

    // Account for last line if it doesn't end with a newline
    if (ptr != input && *(ptr - 1) != '\n') n++;

    char** lines = (char**)malloc((n + 1) * sizeof(char*));
    if (!lines)
    {
        *count = 0;
        return NULL;
    }

    *count = n;
    return NULL;
}
