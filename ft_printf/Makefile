SRC = ft_putnbr.c ft_putchar.c ft_putstr.c ft_putunsigned.c \
      ft_puthexa.c ft_putaddress.c ft_printf.c

OBJ =	$(SRC:.c=.o);

NAME = libftprintf.a

all: $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

clean:
	@rm -fr $(OBJ)

fclean: clean
	@rm -fr $(NAME)

re: fclean all
