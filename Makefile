NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -f
LDFLAGS = -L.
LDLIBS = -lft
HDDIRS = -I.
SRC = arithm.c check_inf_nan1.c check_inf_nan2.c \
	functions1.c functions2.c functions3.c functions4.c \
	print_double.c \
	process_sp1.c process_sp2.c process_sp3.c process_sp4.c process_sp5.c \
	put_d1.c put_d2.c put_d3.c put_d4.c put_d5.c\
	put_double0.c put_double1.c put_double2.c put_ee1.c put_ee2.c put_ee3.c \
	put_f1.c put_f2.c put_f3.c\
	put_long_dbl1.c put_long_dbl2.c put_long_dbl3.c \
	put_long_e.c put_o_u_x1.c put_o_u_x2.c put_p.c \
	put_strings1.c put_strings2.c \
	two.c

OBJ = $(SRC:.c=.o)

HEAD = header.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $< -c -o $@ -I.$(HEAD)

test: all
	@gcc main.c $(NAME)
	@./a.out

clean:
	@$(RM) -f $(OBJ)

fclean: clean
	@$(RM) -f $(NAME)

re: fclean all
