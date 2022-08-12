#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *a, matrix_t *b, matrix_t *c) {
    if (!a || !b)
        return FAILURE;

    if (a->columns != b->columns || a->rows != b->rows)
        return ERRR;

    int row = a->rows;
    int col = a->columns;

    int condition = s21_create_matrix(row, col, c);

    if (!condition) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                c->matrix[i][j] = a->matrix[i][j] + b->matrix[i][j];
            }
        }
    }

    return condition;
}
