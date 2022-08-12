#include "../s21_matrix.h"

void s21_remove_matrix(matrix_t *a) {
    if (a) {
        for (int i = 0; i < a->rows; i++)
            free(a->matrix[i]);
        free(a->matrix);
    }
}
