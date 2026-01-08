HDR = push_swap.h
NAME = push_swap.a
CC = cc -g3
CFLAGS = -c -Werror -Wall -Wextra
AR = ar rcs

LIBFT = libft.a

SRC =\
push_swap.c\
get_list.c\
get_moves.c\
actions.c\
turk_sort.c

SRC_DEBUG = push_swap_debuggers.c

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
