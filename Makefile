NAME=libftprintf.a
SRC=ft_printf.c \
	ft_putnbr_hex.c \
	ft_putnbr.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_strlen.c
OBJS=$(SRC:.c=.o)
CC=cc
CC_FLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $(OBJS)

.c.o:
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

run:
	clear
	$(CC) $(CC_FLAGS) main.c -L. -l:libftprintf.a
	./a.out
