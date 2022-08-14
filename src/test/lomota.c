#include "../test.h"

double get_rand(double min, double max) {
    double val = (double)rand() / RAND_MAX;
    return min + val * (max - min);
}

START_TEST(a_1) {
    matrix_t a;
    s21_create_matrix(2, 2, &a);
    ck_assert_double_eq(a.matrix[0][0], 0);
    ck_assert_double_eq(a.matrix[0][1], 0);
    ck_assert_double_eq(a.matrix[1][0], 0);
    ck_assert_double_eq(a.matrix[0][1], 0);
    s21_remove_matrix(&a);
}
END_TEST

START_TEST(a_2) {
    matrix_t a;
    s21_create_matrix(2, 2, &a);
    a.matrix[0][0] = 1234.1234;
    a.matrix[0][1] = 1234.1234;
    a.matrix[1][0] = 1234.1234;
    a.matrix[1][1] = 1234.1234;
    ck_assert_double_eq(a.matrix[0][0], 1234.1234);
    ck_assert_double_eq(a.matrix[0][1], 1234.1234);
    ck_assert_double_eq(a.matrix[1][0], 1234.1234);
    ck_assert_double_eq(a.matrix[1][1], 1234.1234);
    s21_remove_matrix(&a);
}
END_TEST

START_TEST(a_3) {
    matrix_t a;
    s21_create_matrix(2, 2, &a);
    a.matrix[0][0] = 1234.1234;
    a.matrix[0][1] = 1234.1234;
    a.matrix[1][0] = 1234.1234;
    a.matrix[1][1] = 1234.1234;
    matrix_t b;
    s21_create_matrix(2, 2, &b);
    b.matrix[0][0] = 1234.1234;
    b.matrix[0][1] = 1234.1234;
    b.matrix[1][0] = 1234.1234;
    b.matrix[1][1] = 1234.1234;
    ck_assert_double_eq(a.matrix[0][0], b.matrix[0][0]);
    ck_assert_double_eq(a.matrix[0][1], b.matrix[0][1]);
    ck_assert_double_eq(a.matrix[1][0], b.matrix[1][0]);
    ck_assert_double_eq(a.matrix[0][1], b.matrix[0][1]);
    ck_assert_int_eq(s21_eq_matrix(&a, &b), 1);
    s21_remove_matrix(&a);
    s21_remove_matrix(&b);
}
END_TEST

START_TEST(a_4) {
    matrix_t a;
    s21_create_matrix(2, 2, &a);
    a.matrix[0][0] = 1.1;
    a.matrix[0][1] = 2.2;
    a.matrix[1][0] = 3.3;
    a.matrix[1][1] = 4.4;
    matrix_t b;
    s21_create_matrix(2, 2, &b);
    b.matrix[0][0] = 4.4;
    b.matrix[0][1] = 3.3;
    b.matrix[1][0] = 2.2;
    b.matrix[1][1] = 1.1;
    matrix_t c;
    s21_sum_matrix(&a, &b, &c);
    ck_assert_double_eq(a.matrix[0][0] + b.matrix[0][0], c.matrix[0][0]);
    ck_assert_double_eq(a.matrix[0][1] + b.matrix[0][1], c.matrix[0][1]);
    ck_assert_double_eq(a.matrix[1][0] + b.matrix[1][0], c.matrix[1][0]);
    ck_assert_double_eq(a.matrix[1][1] + b.matrix[1][1], c.matrix[1][1]);
    s21_remove_matrix(&a);
    s21_remove_matrix(&b);
    s21_remove_matrix(&c);
}
END_TEST

START_TEST(a_5) {
    matrix_t a;
    s21_create_matrix(2, 2, &a);
    a.matrix[0][0] = 1.1;
    a.matrix[0][1] = 2.2;
    a.matrix[1][0] = 3.3;
    a.matrix[1][1] = 4.4;
    matrix_t b;
    s21_create_matrix(2, 2, &b);
    b.matrix[0][0] = 4.4;
    b.matrix[0][1] = 3.3;
    b.matrix[1][0] = 2.2;
    b.matrix[1][1] = 1.1;
    matrix_t c;
    s21_sub_matrix(&a, &b, &c);
    ck_assert_double_eq(a.matrix[0][0] - b.matrix[0][0], c.matrix[0][0]);
    ck_assert_double_eq(a.matrix[0][1] - b.matrix[0][1], c.matrix[0][1]);
    ck_assert_double_eq(a.matrix[1][0] - b.matrix[1][0], c.matrix[1][0]);
    ck_assert_double_eq(a.matrix[1][1] - b.matrix[1][1], c.matrix[1][1]);
    s21_remove_matrix(&a);
    s21_remove_matrix(&b);
    s21_remove_matrix(&c);
}
END_TEST

START_TEST(a_6) {
    const int rows = rand() % 100 + 1;
    const int cols = rand() % 100 + 1;
    matrix_t m;
    s21_create_matrix(rows, cols, &m);
    matrix_t check;
    s21_create_matrix(rows, cols, &check);
    double mult_number = get_rand(-10e5, 10e5);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
            check.matrix[i][j] = m.matrix[i][j] * mult_number;
        }
    }
    matrix_t res;
    ck_assert_int_eq(s21_mult_number(&m, mult_number, &res), SUCCESS);
    ck_assert_int_eq(s21_eq_matrix(&check, &res), EQ);
    s21_remove_matrix(&m);
    s21_remove_matrix(&res);
    s21_remove_matrix(&check);
}
END_TEST

START_TEST(a_7) {
    const int rows = rand() % 100 + 1;
    const int cols = rand() % 100 + 1;
    matrix_t m = {0};
    s21_create_matrix(rows, cols, &m);
    matrix_t mtx = {0};
    s21_create_matrix(cols, rows, &mtx);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            m.matrix[i][j] = get_rand(-10e10, 10e10);

    for (int i = 0; i < cols; i++)
        for (int j = 0; j < rows; j++)
            mtx.matrix[i][j] = get_rand(-10e10, 10e10);

    matrix_t check = {0};
    s21_create_matrix(m.rows, mtx.columns, &check);

    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < mtx.columns; j++) {
            check.matrix[i][j] = 0;
            for (int k = 0; k < m.columns; k++)
                check.matrix[i][j] += m.matrix[i][k] * mtx.matrix[k][j];
        }
    }

    matrix_t res = {0};
    ck_assert_int_eq(s21_mult_matrix(&m, &mtx, &res), 0);
    ck_assert_int_eq(s21_eq_matrix(&check, &res), EQ);

    s21_remove_matrix(&m);
    s21_remove_matrix(&mtx);
    s21_remove_matrix(&res);
    s21_remove_matrix(&check);
}
END_TEST

START_TEST(a_8) {
    const int rows = 2;
    const int cols = 3;
    matrix_t m = {0};
    s21_create_matrix(rows, cols, &m);
    matrix_t mtx = {0};
    s21_create_matrix(cols, rows, &mtx);

    for (int i = 0, c = 1; i < rows; i++)
        for (int j = 0; j < cols; j++)
            m.matrix[i][j] = c++;

    for (int i = 0, c = 7; i < cols; i++)
        for (int j = 0; j < rows; j++)
            mtx.matrix[i][j] = c++;

    matrix_t check = {0};
    s21_create_matrix(m.rows, mtx.columns, &check);
    check.matrix[0][0] = 58;
    check.matrix[0][1] = 64;
    check.matrix[1][0] = 139;
    check.matrix[1][1] = 154;

    matrix_t res = {0};
    ck_assert_int_eq(s21_mult_matrix(&m, &mtx, &res), 0);
    ck_assert_int_eq(s21_eq_matrix(&check, &res), EQ);

    s21_remove_matrix(&m);
    s21_remove_matrix(&mtx);
    s21_remove_matrix(&res);
    s21_remove_matrix(&check);
}
END_TEST

START_TEST(a_9) {
    const int rows = rand() % 100 + 1;
    const int cols = rand() % 100 + 1;
    matrix_t m = {0};
    s21_create_matrix(rows, cols, &m);

    matrix_t check = {0};
    s21_create_matrix(cols, rows, &check);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double rand_val = get_rand(-10e10, 10e10);
            m.matrix[i][j] = rand_val;
            check.matrix[j][i] = rand_val;
        }
    }

    matrix_t res = {0};
    ck_assert_int_eq(s21_transpose(&m, &res), 0);
    ck_assert_int_eq(s21_eq_matrix(&check, &res), EQ);

    s21_remove_matrix(&m);
    s21_remove_matrix(&res);
    s21_remove_matrix(&check);
}
END_TEST

START_TEST(a_10) {
    matrix_t a = {0};
    s21_create_matrix(3, 3, &a);
    matrix_t res = {0};
    s21_create_matrix(3, 3, &res);
    matrix_t m;
    res.matrix[0][0] = 0;
    res.matrix[0][1] = 10;
    res.matrix[0][2] = -20;
    res.matrix[1][0] = 4;
    res.matrix[1][1] = -14;
    res.matrix[1][2] = 8;
    res.matrix[2][0] = -8;
    res.matrix[2][1] = -2;
    res.matrix[2][2] = 4;

    a.matrix[0][0] = 1;
    a.matrix[0][1] = 2;
    a.matrix[0][2] = 3;
    a.matrix[1][0] = 0;
    a.matrix[1][1] = 4;
    a.matrix[1][2] = 2;
    a.matrix[2][0] = 5;
    a.matrix[2][1] = 2;
    a.matrix[2][2] = 1;
    s21_calc_complements(&a, &m);
    ck_assert_int_eq(s21_eq_matrix(&res, &m), EQ);
    s21_remove_matrix(&m);
    s21_remove_matrix(&a);
    s21_remove_matrix(&res);
}
END_TEST

START_TEST(a_11) {
    matrix_t A, B, C;
    s21_create_matrix(3, 3, &A);
    s21_create_matrix(3, 3, &C);
    A.matrix[0][0] = 1.0;
    A.matrix[0][1] = 2.0;
    A.matrix[0][2] = 3.0;
    A.matrix[1][0] = 0.0;
    A.matrix[1][1] = 4.0;
    A.matrix[1][2] = 2.0;
    A.matrix[2][0] = 5.0;
    A.matrix[2][1] = 2.0;
    A.matrix[2][2] = 1.0;
    s21_calc_complements(&A, &B);
    C.matrix[0][0] = 0.0;
    C.matrix[0][1] = 10.0;
    C.matrix[0][2] = -20.0;
    C.matrix[1][0] = 4.0;
    C.matrix[1][1] = -14.0;
    C.matrix[1][2] = 8.0;
    C.matrix[2][0] = -8.0;
    C.matrix[2][1] = -2.0;
    C.matrix[2][2] = 4.0;
    int res = s21_eq_matrix(&B, &C);
    ck_assert_int_eq(res, EQ);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
}
END_TEST

START_TEST(a_12) {
    matrix_t a = {0};
    matrix_t b = {0};
    ck_assert_int_eq(s21_calc_complements(&a, &b), FAILURE);
}
END_TEST

START_TEST(a_13) {
    matrix_t A, C;
    s21_create_matrix(3, 3, &A);
    s21_create_matrix(3, 3, &C);
    C.matrix[0][0] = 1.0;
    C.matrix[0][1] = -1.0;
    C.matrix[0][2] = 1.0;
    C.matrix[1][0] = -38.0;
    C.matrix[1][1] = 41.0;
    C.matrix[1][2] = -34.0;
    C.matrix[2][0] = 27.0;
    C.matrix[2][1] = -29.0;
    C.matrix[2][2] = 24.0;
    A.matrix[0][0] = 2.0;
    A.matrix[0][1] = 5.0;
    A.matrix[0][2] = 7.0;
    A.matrix[1][0] = 6.0;
    A.matrix[1][1] = 3.0;
    A.matrix[1][2] = 4.0;
    A.matrix[2][0] = 5.0;
    A.matrix[2][1] = -2.0;
    A.matrix[2][2] = -3.0;
    matrix_t B;
    s21_inverse_matrix(&A, &B);
    int res = s21_eq_matrix(&B, &C);
    ck_assert_int_eq(res, EQ);
    s21_remove_matrix(&A);
    s21_remove_matrix(&B);
    s21_remove_matrix(&C);
}
END_TEST

START_TEST(a_14) {
    const int size = 3;
    matrix_t m = {0};
    s21_create_matrix(size, size, &m);
    m.matrix[0][0] = 1;
    m.matrix[0][1] = 2;
    m.matrix[0][2] = 3;
    m.matrix[1][1] = 4;
    m.matrix[1][2] = 2;
    m.matrix[2][0] = 5;
    m.matrix[2][1] = 2;
    m.matrix[2][2] = 1;

    matrix_t expected = {0};
    s21_create_matrix(size, size, &expected);
    expected.matrix[0][1] = 10;
    expected.matrix[0][2] = -20;
    expected.matrix[1][0] = 4;
    expected.matrix[1][1] = -14;
    expected.matrix[1][2] = 8;
    expected.matrix[2][0] = -8;
    expected.matrix[2][1] = -2;
    expected.matrix[2][2] = 4;

    matrix_t res = {0};
    s21_calc_complements(&m, &res);

    ck_assert_int_eq(s21_eq_matrix(&expected, &res), EQ);
    s21_remove_matrix(&m);
    s21_remove_matrix(&res);
    s21_remove_matrix(&expected);
}
END_TEST

START_TEST(a_15) {
    matrix_t matrix;
    s21_create_matrix(3, 3, &matrix);
    int count = 1;
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.columns; j++) {
            matrix.matrix[i][j] = count++;
        }
    }
    matrix.matrix[2][2] = 10;
    double res;
    int ret = s21_determinant(&matrix, &res);
    ck_assert_uint_eq(res, -3);
    ck_assert_int_eq(ret, 0);
    s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(a_16) {
    matrix_t matrix;
    s21_create_matrix(1, 1, &matrix);
    matrix.matrix[0][0] = 1;
    double res;
    int ret = s21_determinant(&matrix, &res);
    ck_assert_uint_eq(res, 1);
    ck_assert_int_eq(ret, 0);
    s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(a_17) {
    matrix_t a;
    matrix_t b;
    double f = 0;
    ck_assert_int_eq(s21_eq_matrix(&a, &b), 0);
    ck_assert_int_eq(s21_determinant(&a, &f), 2);
    s21_create_matrix(1, 1, &a);
    s21_create_matrix(2, 2, &b);
    ck_assert_int_eq(s21_eq_matrix(&a, &b), 0);
    s21_remove_matrix(&a);
    s21_create_matrix(2, 2, &a);
    a.matrix[0][0] = 142.51234;
    ck_assert_int_eq(s21_eq_matrix(&a, &b), 0);
    s21_remove_matrix(&a);
    s21_remove_matrix(&b);
}
END_TEST


Suite* s21_matrix_test(void) {
    Suite *s = suite_create("!!!TEST!!!");
    TCase *pum;

    pum = tcase_create("--ALL_TESTS--");
    tcase_add_test(pum, a_1);
    tcase_add_test(pum, a_2);
    tcase_add_test(pum, a_3);
    tcase_add_test(pum, a_4);
    tcase_add_test(pum, a_5);
    tcase_add_test(pum, a_6);
    tcase_add_test(pum, a_7);
    tcase_add_test(pum, a_8);
    tcase_add_test(pum, a_9);
    tcase_add_test(pum, a_10);
    tcase_add_test(pum, a_11);
    tcase_add_test(pum, a_12);
    tcase_add_test(pum, a_13);
    tcase_add_test(pum, a_14);
    tcase_add_test(pum, a_15);
    tcase_add_test(pum, a_16);
    tcase_add_test(pum, a_17);
    suite_add_tcase(s, pum);

    return s;
}