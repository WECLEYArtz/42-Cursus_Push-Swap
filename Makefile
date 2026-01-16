HDR = push_swap.h
CC = cc -g3
CFLAGS = -c -Werror -Wall -Wextra
AR = ar rcs
BIN = push_swap
BIN_B = checker

NAME = push_swap.a
LIBFT = libft/libft.a

SRC_B =\
checker_bonus.c

SRC =\
actions.c\
actions_caller.c\
examin_status.c\
final_sort.c\
ft_atoi_custom.c\
get_list.c\
get_target_moves.c\
hard_sort.c\
init_stack.c\
push_swap.c\
turk_sort.c

OBJ = $(SRC:.c=.o)

all: $(BIN)

bonus: $(BIN_B)

$(BIN): $(NAME) $(LIBFT)
	@echo "\n[ Compiling... ]"
	cc -o $(BIN) $^

$(BIN_B):
	@echo "No bonus made yet (wip)"

$(LIBFT) : Libft

Libft : 
	@echo "\n[ Upating Libft... ]"
	make all bonus -C ./libft CC="cc -g3"

$(NAME):  $(OBJ) 
	@echo "\n[ Updated Push_swap Archive  ]"

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
