#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *a, matrix_t *b, matrix_t *c) {
    if (s21_matrix_checker(a) || s21_matrix_checker(b))
        return FAILURE;

    if (a->columns != b->rows)
        return ERRR;

    int res = s21_create_matrix(a->rows, b->columns, c);

    if (res == SUCCESS) {
        for (int i = 0; i < a->rows; i++) {
            for (int j = 0; j < b->columns; j++) {
                for (int m = 0; m < b->rows; m++) {
                    c->matrix[i][j] += a->matrix[i][m] * b->matrix[m][j];
                }
            }
        }
    }

    return res;
}
