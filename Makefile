CFLAGS= -Wall -Wextra -Werror -g
NAME =  push_swap
SRC= src/main.c src/garbage_colector.c src/push_swap.c src/parsing_part.c src/error_exit.c src/ft_strlen.c src/split.c
CC =  cc

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
.SECONDARY: $(OBJ)
