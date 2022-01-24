NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRCS = ft_printf.c parse_format.c print_formatted_arg.c print_char_string.c \
print_pointer.c print_utils.c print_decimal.c print_hex.c print_formatting.c

OBJS = $(SRCS:.c=.o)

all bonus: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $^

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
