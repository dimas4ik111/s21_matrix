CC = gcc
CFLAGS = -Wall -Werror -Wextra
CFLAGS_T=--coverage
SRC = ./library/s21_create_matrix.c \
	./library/s21_calc_complements.c \
    ./library/s21_determinant.c \
	./library/s21_eq_matrix.c \
	./library/s21_help_func.c \
	./library/s21_inverse_matrix.c \
	./library/s21_mult_matrix.c \
	./library/s21_mult_number.c \
	./library/s21_remove_matrix.c \
	./library/s21_sub_matrix.c \
	./library/s21_sum_matrix.c \
	./library/s21_transpose.c
OBJ = $(SRC:.c=.o)
SRC_TEST = ./test/test.c \
			./test/lomota.c
OBJ_TEST = $(SRC_TEST:.c=.o)
OBJ_DIR=./obj/
LIB = s21_matrix.a

all : $(LIB)

$(LIB) : $(OBJ) s21_matrix.h
	ar rcs $(LIB) $(OBJ)
	ranlib $(LIB)

test : $(LIB) $(OBJ_TEST)
	$(CC) $^ -lcheck -lgcov -o s21_matrix_test.out
	./s21_matrix_test.out

gcov_report: $(OBJ_TEST) $(LIB) s21_calc_complements.o s21_determinant.o s21_eq_matrix.o s21_help_func.o s21_inverse_matrix.o s21_mult_matrix.o s21_mult_number.o s21_remove_matrix.o s21_sub_matrix.o s21_sum_matrix.o s21_transpose.o
	@$(CC) $(CFLAGS) $^ -lcheck -lgcov -o s21_tests_matrix.out
	@./s21_tests_matrix.out
	@gcov -a -b ./*.gcda
	@gcovr --html-details coverage.html

s21_calc_complements.o : ./library/s21_calc_complements.c
	@$(CC) $(CFLAGS) $(CFLAGS_T) -c $< -o $@
s21_determinant.o : ./library/s21_determinant.c
	@$(CC) $(CFLAGS) $(CFLAGS_T) -c $< -o $@
s21_eq_matrix.o : ./library/s21_eq_matrix.c
	@$(CC) $(CFLAGS) $(CFLAGS_T) -c $< -o $@
s21_help_func.o : ./library/s21_help_func.c
	@$(CC) $(CFLAGS) $(CFLAGS_T) -c $< -o $@
s21_inverse_matrix.o : ./library/s21_inverse_matrix.c
	@$(CC) $(CFLAGS) $(CFLAGS_T) -c $< -o $@
s21_mult_matrix.o : ./library/s21_mult_matrix.c
	@$(CC) $(CFLAGS) $(CFLAGS_T) -c $< -o $@
s21_mult_number.o : ./library/s21_mult_number.c
	@$(CC) $(CFLAGS) $(CFLAGS_T) -c $< -o $@
s21_remove_matrix.o : ./library/s21_remove_matrix.c
	@$(CC) $(CFLAGS) $(CFLAGS_T) -c $< -o $@
s21_sub_matrix.o : ./library/s21_sub_matrix.c
	@$(CC) $(CFLAGS) $(CFLAGS_T) -c $< -o $@
s21_sum_matrix.o : ./library/s21_sum_matrix.c
	@$(CC) $(CFLAGS) $(CFLAGS_T) -c $< -o $@
s21_transpose.o : ./library/s21_transpose.c
	@$(CC) $(CFLAGS) $(CFLAGS_T) -c $< -o $@

clean : 
	rm -rf $(OBJ) $(OBJ_TEST)
	rm -rf ./*/*.o ./*.o
	rm -rf */*.gcda */*.gcno */*.gcov */*.info *.out
	rm -rf *.gcda *.gcno *.gcc *.info *.gcov
	rm -rf s21_matrix.a
	rm -rf coverage.*


# .SILENT: $(OBJ) $(OBJ_TEST) $(OBJ_REPORT) $(LIB) test clean

.PHONY: all test clean