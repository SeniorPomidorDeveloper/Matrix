#ifndef MATRIX_H
#define MATRIX_H

#include "structs.h"
#include "error_codes.h"

int init_Matrix(Matrix **matrix, const size_t rows, const size_t cols, const size_t size_data); // Инициализация матрицы

int change_Matrix(Matrix *matrix, const size_t row, const size_t col, const void *data); // Изменение элемента матрицы
int get_Matrix(const Matrix *matrix, const size_t row, const size_t col, void *data); // Получение элемента матрицы

int copy_Matrix(const Matrix *src, Matrix **dst); // Копирование матрицы

void free_Matrix(Matrix *matrix); // Освобождение памяти

#endif // MATRIX_H