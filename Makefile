NAME = hash

FLAGS = -Wall -Wextra -Werror

LIBA = ./libft/libftprintf.a

SRC = main.c

SRC_O = main.o

all: $(SRC_O)
	@ make -C ./libft
	gcc $(FLAGS) $(SRC_O) $(LIBA) -o $(NAME)

%.o: %.c
	@gcc -c -Wall -Wextra -Werror -o $@ $<

clean:
	@ make clean -C ./libft
	@rm -f *.o

fclean: clean
	@rm -f checker push_swap $(LIBA)

re: fclean all
