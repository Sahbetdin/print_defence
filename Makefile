NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -f
LDFLAGS = -L.
LDLIBS = -lft
HDDIRS = -I.
SRC = process_sp1.c process_sp2.c process_sp3.c process_sp4.c \
	put_hex_oct.c put_strings.c check_inf_nan.c \
	functions1.c functions2.c functions3.c functions4.c \
	put_ee1.c put_ee2.c put_ee3.c \
	put_d1.c put_d2.c put_d3.c put_d4.c \
	put_long_dbl1.c put_long_dbl2.c put_long_dbl3.c \
	put_double.c two.c print_double.c arithm.c \
	put_p.c  put_Le.c put_f1.c \
	
	
OBJ = $(SRC:.c=.o)

HEAD = test_header.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
#	@ar rc $(NAME) $(OBJ)
	@ar rc $@ $^
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $< -c -o $@ -I.$(HEAD)
#	@gcc -I $(HEAD) -o $@ -c $<

test: all
	@gcc main_e.c $(NAME)
	@./a.out

clean:
	@$(RM) -f $(OBJ)

fclean: clean
	@$(RM) -f $(NAME)

re: fclean all
