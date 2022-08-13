#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

#define SUCCESS 0 // OK 
#define FAILURE 1 // Ошибка, некорректная матрица
#define ERRR 2 // Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой нельзя провести вычисления и т.д.)

#define EQ 1
#define NO_EQ 0


typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

// library function

int s21_create_matrix(int rows, int columns, matrix_t *c);

void s21_remove_matrix(matrix_t *a);

int s21_eq_matrix(matrix_t *a, matrix_t *b);

int s21_sum_matrix(matrix_t *a, matrix_t *b, matrix_t *c);

int s21_sub_matrix(matrix_t *a, matrix_t *b, matrix_t *c);

int s21_mult_number(matrix_t *a, double number, matrix_t *c);

int s21_mult_matrix(matrix_t *a, matrix_t *b, matrix_t *c);

int s21_transpose(matrix_t *a, matrix_t *c);

int s21_calc_complements(matrix_t *a, matrix_t *c);

int s21_determinant(matrix_t *a, double *c);

int s21_inverse_matrix(matrix_t *a, matrix_t *c);

// help function

int s21_matrix_checker(matrix_t* a);

void s21_cofacrot_matrix(double **src, double **dst, int jump_r, int jump_col, int size);

int s21_calculator(matrix_t* a, matrix_t* c);

double s21_determ(double **m, int size);

#endif  // SRC_S21_MATRIX_H_
