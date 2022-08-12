CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = library/*.c
SRC_TEST = test/*.c
OBJ = $(SRC:.c=.o)
OBJ_TEST = $(SRC_TEST:.c=.o)
LIB = s21_matrix.a

$(LIB) : $(OBJ) s21_matrix.h
	ar rcs $(LIB) $(OBJ)
	ranlib s21_matrix.a

clean : 
	rm -rf *.a 
	rm -rf library/*.o
	rm -rf *.out
	rm -rf *.html

.PHONY: all test clean

# .SILENT: $(OBJ) $(OBJ_TEST) $(OBJ_REPORT) $(LIB) test clean
