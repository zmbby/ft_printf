NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

CC = cc

CFILES = ft_printf.c utils.c

OBJM = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJM)
	ar rcs $(NAME) $(OBJM)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJM)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re