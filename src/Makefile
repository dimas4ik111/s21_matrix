CC = gcc
# CFLAGS = -Wall -Werror -Wextra
SRC = ./library/s21_determinant.c\
	./library/s21_eq_matrix.c\
	./library/s21_help_func.c\
	./library/s21_inverse_matrix.c\
	./library/s21_mult_matrix.c\
	./library/s21_mut_number.c\
	./library/s21_remove_matrix.c\
	./library/s21_sub_matrix.c\
	./library/s21_sum_matrix.c\
	./library/s21_transpose.c\
	./library/s21_calc_complements.c\
	./library/s21_create_matrix.c\
OBJ = $(SRC:.c=.o)
# OBJ_TEST = $(SRC_TEST:.c=.o)
LIB = s21_matrix.a

all : $(LIB)

$(LIB) : $(OBJ) s21_matrix.h
	ar rcs $(LIB) $(OBJ)
	ranlib $(LIB)

clean : 
	rm -rf *.a 
	rm -rf library/*.o
	rm -rf *.out
	rm -rf *.html

# .SILENT: $(OBJ) $(OBJ_TEST) $(OBJ_REPORT) $(LIB) test clean

.PHONY: all test clean