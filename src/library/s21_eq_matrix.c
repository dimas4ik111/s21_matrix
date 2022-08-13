#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *a, matrix_t *b) {
    int res = NO_EQ;

    if (a->columns == b->columns && a->rows == b->rows) {
        int rows = a->rows;
        int columns = a->columns;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (a->matrix[i][j] == b->matrix[i][j]) {
                    res = EQ;
                } else {
                    res = NO_EQ;
                    break;
                }
            }
            if (res == NO_EQ)
                break;
        }
    }
    return res;
}
