#ifndef ERROR_CODES_H
#define ERROR_CODES_H

typedef enum Error_code
{
    SUCCESS,
    ERROR_ALLOCATION,
    INIT_MATRIX_ERROR,
    CHANGE_MATRIX_ERROR,
    COPY_MATRIX_ERROR
} Error_code;

typedef enum Warning_code
{
    NOT_FOUND = 4,
    NOT_INIT
} Warning_code;

#endif // ERROR_CODES_H