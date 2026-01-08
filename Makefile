HDR = push_swap.h
NAME = push_swap.a
CC = cc -g3
CFLAGS = -c -Werror -Wall -Wextra
AR = ar rcs

LIBFT = libft.a

SRC =\
actions.c\
actions_caller.c\
get_list.c\
get_moves.c\
push_swap.c\
turk_sort.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)

$(LIBFT):
	make all bonus -C ./libft CC="cc -g3"

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
