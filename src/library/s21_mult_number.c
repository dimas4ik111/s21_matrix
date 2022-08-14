#include "../s21_matrix.h"

int s21_mult_number(matrix_t *a, double number, matrix_t *c) {
    if (s21_matrix_checker(a))
        return FAILURE;

    int res = s21_create_matrix(a->rows, a->columns, c);

    if (!res) {
        for (int i = 0; i < a->rows; i++) {
            for (int j = 0; j < a->columns; j++) {
                c->matrix[i][j] = a->matrix[i][j] * number;
            }
        }
    }
    return res;
}
