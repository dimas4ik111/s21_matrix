#include "../s21_matrix.h"

int s21_matrix_checker(matrix_t* a) {
    int res = 0;
    if (a->rows <= 0 || a->columns <= 0)
        res = 1;
    return res;
}

int bs21_calculator(matrix_t* a, matrix_t* c) {
    int res = ERRR;
    if (a->rows == 1) {
        c->matrix[0][0] = 1;
        return res;
    }

    matrix_t help_struct;

    res = s21_create_matrix(a->rows, a->rows, &help_struct);

    if (!res) {
        for (int i = 0; i < a->rows; i++) {
            for (int j = 0; j < a->columns; j++) {
                s21_cofacrot_matrix(a->matrix, help_struct.matrix, i, j, a->rows);
                int sign = ((i + j) % 2 == 0) ? 1 : -1;
                c->matrix[i][j] = sign * s21_determ(help_struct.matrix, a->rows - 1);
            }
        }
        s21_remove_matrix(&help_struct);
    }
    return res;
}

double s21_determ(double **m, int size) {
    if (size == 1)
        return m[0][0];

    double res = 0;

    matrix_t tmp;
    int rrr = s21_create_matrix(size, size, &tmp);

    if (!rrr) {
        int sign = 1;
        for (int i = 0; i < size; i++) {
            s21_cofacrot_matrix(m, tmp.matrix, 0, i, size);
            res += sign * m[0][i] * s21_determ(tmp.matrix, size - 1);
            sign = -sign;
        }

        s21_remove_matrix(&tmp);
    }

    return res;
}

void s21_cofacrot_matrix(double **src, double **dst, int jump_r, int jump_col, int size) {
    for (int i = 0, row = 0; row < size; row++) {
        for (int j = 0, col = 0; col < size; col++) {
            if (row != jump_r && col != jump_col) {
                dst[i][j] = src[row][col];
                j++;
                if (j == size - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
