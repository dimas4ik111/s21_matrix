#include "../s21_matrix.h"

int s21_determinant(matrix_t *a, double *c) {
    int res = s21_matrix_checker(a);
    if (res)
        return res;
    if (a->rows == a->columns) {
        res = SUCCESS;
    } else {
        res = ERRR;
    }

    if (res == SUCCESS) {
        *c = 0;
        if (a->rows == 1) {
            *c = a->matrix[0][0];
        } else {
            *c = s21_determ(a->matrix, a->rows);
        }
    }
    return res;
}
