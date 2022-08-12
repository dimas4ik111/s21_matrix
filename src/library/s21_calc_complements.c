#include "../s21_matrix.h"

int calculator(matrix_t* a, matrix_t* c);

int s21_calc_complements(matrix_t *a, matrix_t *c) {
    if (s21_matrix_checker(a))
        return FAILURE;
    if (a->rows != a->columns)
        return ERRR;

    int res = s21_create_matrix(a->rows, a->columns, c);

    if (res == SUCCESS) {
        calculator(a, c);
    }
}

int calculator(matrix_t* a, matrix_t* c) {
    
}
