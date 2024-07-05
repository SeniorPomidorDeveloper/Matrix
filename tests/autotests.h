#ifndef AUTOTESTS_H
#define AUTOTESTS_H

#include "../src/matrix.h"

typedef enum Status
{
    OK,
    ERROR
} Status;

int init_test(Matrix **matrix);
int change_test(Matrix **matrix);
int get_test(Matrix **matrix);
int copy_test(Matrix **matrix);

void test();

#endif // AUTOTESTS_H