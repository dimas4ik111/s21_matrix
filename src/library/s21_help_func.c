#include "../s21_matrix.h"

int s21_matrix_checker(matrix_t* a) {
    int res = 0;
    if (a->rows <= 0 || a->columns <= 0 || !a)
        res = 1;
    return res;
}

