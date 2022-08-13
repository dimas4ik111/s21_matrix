#include "../test.h"

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");
    int no_failed = 0;

    Suite *s1 = s21_matrix_test("TEST");

    SRunner *matrix_test;

    matrix_test = srunner_create(s1);

    srunner_set_fork_status(matrix_test, CK_NOFORK);

    srunner_run_all(matrix_test, CK_NORMAL);

    no_failed += srunner_ntests_failed(matrix_test);

    srunner_free(matrix_test);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
