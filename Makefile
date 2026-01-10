HDR = push_swap.h
CC = cc -g3
CFLAGS = -c -Werror -Wall -Wextra
AR = ar rcs
BIN = push_swap

NAME = push_swap.a
LIBFT = libft/libft.a

SRC =\
actions.c\
actions_caller.c\
get_list.c\
get_moves.c\
push_swap.c\
turk_sort.c\
final_sort.c

OBJ = $(SRC:.c=.o)

all: $(BIN)

$(BIN): $(NAME) $(LIBFT) 
	cc -o $(BIN) $^

$(LIBFT):
	make all bonus -C ./libft CC="cc -g3"

$(NAME): $(OBJ)

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) $<
	$(AR) $(NAME) $@

clean: 
	rm -f $(OBJ)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: fclean all clean re
