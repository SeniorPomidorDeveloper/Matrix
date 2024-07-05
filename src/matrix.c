#include "matrix.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int init_Matrix(Matrix **matrix, const size_t rows, const size_t cols, const size_t size_data)
{
    *matrix = (Matrix *) malloc(sizeof(Matrix));
    if (*matrix == NULL) return INIT_MATRIX_ERROR;
    (*matrix)->data = (void **) malloc(sizeof(void *) * rows);
    if ((*matrix)->data == NULL)
    {
        free(*matrix);
        return INIT_MATRIX_ERROR;
    }
    for (size_t i = 0; i < rows; ++i) {
        (*matrix)->data[i] = (void *) malloc(cols * size_data);
        if ((*matrix)->data[i] == NULL) 
        {
            for (; i != 0; --i)
            {
                free((*matrix)->data[i - 1]);
            }
            free(*matrix);
            return INIT_MATRIX_ERROR;
        }
    }
    (*matrix)->count_rows = rows;
    (*matrix)->count_cols = cols;
    (*matrix)->size_data = size_data;
    return SUCCESS;
}

int change_Matrix(Matrix *matrix, const size_t row, const size_t col, const void *data)
{
    if (row >= matrix->count_rows || col >= matrix->count_cols) return NOT_FOUND;
    memcpy(matrix->data[row] + col * matrix->size_data, data, matrix->size_data);
    return SUCCESS;
}

int get_Matrix(const Matrix *matrix, const size_t row, const size_t col, void *data)
{
    if (row >= matrix->count_rows || col >= matrix->count_cols) return NOT_FOUND;
    memcpy(data, matrix->data[row] + col * matrix->size_data, matrix->size_data);
    return SUCCESS;
}

int copy_Matrix(const Matrix *src, Matrix **dst)
{
    if (src == NULL)
    {
        *dst = NULL;
        return NOT_INIT;
    } 
    if (init_Matrix(dst, src->count_rows, src->count_cols, src->size_data) != SUCCESS) return COPY_MATRIX_ERROR;
    for (size_t i = 0; i < src->count_rows; ++i)
    {
        memcpy((*dst)->data[i], src->data[i], src->count_cols * src->size_data);
    }
    return SUCCESS;
}

void free_Matrix(Matrix *matrix)
{
    for (size_t i = 0; i < matrix->count_rows; ++i)
    {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}