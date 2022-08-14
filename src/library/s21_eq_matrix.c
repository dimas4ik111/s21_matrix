#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *a, matrix_t *b) {
    if (s21_matrix_checker(a) || s21_matrix_checker(b) ||
        a->rows != b->rows || a->columns != b->columns) {
        return NO_EQ;
    }

    int res = EQ;

    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->columns; j++) {
            if (fabs(a->matrix[i][j] - b->matrix[i][j]) > 1e-07) {
                res = NO_EQ;
                break;
            }
        }
    }
    return res;
}