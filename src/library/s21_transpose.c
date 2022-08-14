#include "../s21_matrix.h"

int s21_transpose(matrix_t *a, matrix_t *c) {
    if (s21_matrix_checker(a))
        return FAILURE;

    int res = s21_create_matrix(a->columns, a->rows, c);

    if (res == SUCCESS) {
        for (int i = 0; i < a->rows; i ++) {
            for (int j = 0; j < a->columns; j++) {
                c->matrix[j][i] = a->matrix[i][j];
            }
        }
    }

    return res;
}
