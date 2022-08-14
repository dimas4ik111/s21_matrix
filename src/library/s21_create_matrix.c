#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    int condition = SUCCESS;

    if (rows <= 0 || columns <= 0)
        return FAILURE;

    result->matrix = calloc(rows, sizeof(double*));

    if (result->matrix != NULL) {
        result->columns = columns;
        result->rows = rows;
        for (int i = 0; i < rows; i++) {
            result->matrix[i] = calloc(columns, sizeof(double));
            if (result->matrix[i] == NULL) {
                condition = FAILURE;
                break;
            }
        }
    } else {
        condition = FAILURE;
    }

    return condition;
}
