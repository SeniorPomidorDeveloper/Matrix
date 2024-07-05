#include "autotests.h"

#include <stdio.h>

void print_ERROR_message(size_t ERROR_num)
{
    switch (ERROR_num)
    {
    case 0:
        printf("[ERROR] Init_test работает не корректно!\n");
        break;
    case 1:
        printf("[ERROR] Change_test работает не корректно!\n");
        break;
    case 2:
        printf("[ERROR] Get_test работает не корректно!\n");
        break;
    case 3:
        printf("[ERROR] Copy_test работает не корректно!\n");
    }
    printf("Работа программы была завершена!\n");
}

void print_statistic_message(size_t count_OK)
{
    printf("Колличество выполненных тестов - OK: %zu\n", count_OK);
}

int init_test(Matrix **matrix)
{
    if (init_Matrix(matrix, 100, 100, sizeof(size_t)) == INIT_MATRIX_ERROR) return ERROR;
    if (*matrix == NULL) return ERROR;
    if ((*matrix)->data == NULL) return ERROR;
    if ((*matrix)->count_rows != 100) return ERROR;
    if ((*matrix)->count_cols != 100) return ERROR;
    return OK;
}

int change_test(Matrix **matrix)
{
    for (size_t i = 0; i < (*matrix)->count_rows; ++i)
    {
        for (size_t j = 0; j < (*matrix)->count_cols; ++j)
        {
            size_t num = i * j;
            if (change_Matrix(*matrix, i, j, &num) == NOT_FOUND) return ERROR;
        }
    }
    return OK;
}

int get_test(Matrix **matrix)
{
    for (size_t i = 0; i < (*matrix)->count_rows; ++i)
    {
        for (size_t j = 0; j < (*matrix)->count_cols; ++j)
        {
            size_t num;
            if (get_Matrix(*matrix, i, j, &num) == NOT_FOUND) return ERROR;
            if (num != i * j) return ERROR;
        }
    }
    return OK;
}

int copy_test(Matrix **matrix)
{
    Matrix *copy = NULL;
    if (copy_Matrix(*matrix, &copy) == COPY_MATRIX_ERROR) return ERROR;
    for (size_t i = 0; i < (*matrix)->count_rows; ++i)
    {
        for (size_t j = 0; j < (*matrix)->count_cols; ++j)
        {
            size_t num;
            if (get_Matrix(*matrix, i, j, &num) == NOT_FOUND) return ERROR;
            if (get_Matrix(copy, i, j, &num) == NOT_FOUND) return ERROR;
            if (num != i * j) return ERROR;
        }
    }
    free_Matrix(copy);
    return OK;
}

void test()
{
    Matrix *matrix;
    int (*tests[])(Matrix **) = {&init_test, &change_test, &get_test, &copy_test};
    size_t count_OK = 0;
    for (; count_OK < 4; ++count_OK)
    {
        if (tests[count_OK](&matrix) == ERROR)
        {
            print_ERROR_message(count_OK);
            break;
        }
    }
    free_Matrix(matrix);
    print_statistic_message(count_OK);
}