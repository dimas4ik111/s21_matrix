#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *a, matrix_t *c) {
    int res = -1;
    if (s21_matrix_checker(a))
        return 1;
    if (a->columns != a->rows) {
        res = ERRR;
    } else {
        double det = 0;
        s21_determinant(a, &det);

        if (fabs(det) > 1e-7) {
            matrix_t help1, help2;
            s21_calc_complements(a, &help1);
            s21_transpose(&help1, &help2);
            s21_mult_number(&help2, 1.0 / det, c);
            s21_remove_matrix(&help1);
            s21_remove_matrix(&help2);
            res = SUCCESS;
        } else {
            res = ERRR;
        }
    }
    return res;
}
