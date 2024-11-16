CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_putchar.c ft_putnbr.c ft_strlen.c ft_putstr.c \
ft_more_format.c ft_printf.c ft_puthex.c ft_unputnbr.c	ft_putnb_hex.c


OBJECTS = $(SRCS:.c=.o)
NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJECTS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all re fclean clean bonus