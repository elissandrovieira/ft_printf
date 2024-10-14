NAME=libftprintf.a
SRC=ft_printf.c
OBJS=$(SRC:.c=.o)
CC=cc
CC_FLAGS=-Wall -Wextra -Werror

all: libft $(NAME)

libft:
	make -C libft

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
	$(CC) $(CC_FLAGS) main.c -L. -l:libft.a -l:libftprintf.a
