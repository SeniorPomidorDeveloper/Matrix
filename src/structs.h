#ifndef STRUCTS_H
#define STRUCTS_H

#include <stddef.h>

typedef struct Matrix
{
    void **data;
    size_t count_rows;
    size_t count_cols;
    size_t size_data;
} Matrix;

#endif // STRUCTS_H