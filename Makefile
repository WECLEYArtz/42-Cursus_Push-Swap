HDR = push_swap.h
CC = cc -g3
CFLAGS = -Werror -Wall -Wextra
AR = ar rcs


NAME = push_swap.a
LIBFT = libft/libft.a


BIN = push_swap
BIN_B = checker_bonus

SRC_MAIN	= push_swap.c
SRC_MAIN_B	= checker_bonus.c


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
turk_sort.c


OBJ = $(SRC:.c=.o)
OBJ_MAIN_B = $(SRC_MAIN_B:.c=.o)

all: $(BIN)

bonus: $(BIN_B)

$(BIN): $(SRC_MAIN) $(NAME) $(LIBFT)
	@echo "\n[ Compiling... ]"
	$(CC) $(CFLAGS) -o $(BIN) $^

$(BIN_B): $(SRC_MAIN_B) $(NAME) $(LIBFT)
	@echo "\n[ Compiling bonus... ]"
	$(CC) $(CFLAGS) -o $(BIN_B) $^

$(LIBFT) : Libft

Libft : 
	@echo "\n[ Upating Libft... ]"
	make all bonus -C ./libft CC="cc -g3"

$(NAME):  $(OBJ) 
	@echo "\n[ Updated Push_swap Archive ]"

%.o: %.c $(HDR)
	$(CC) -c $(CFLAGS) $<
	$(AR) $(NAME) $@

clean: 
	rm -f $(OBJ) $(OBJ_MAIN_B)
	make clean -C ./libft

fclean: clean
	rm -f $(BIN) $(BIN_B) $(NAME) $(LIBFT)
	make fclean -C ./libft

re: fclean all

.PHONY: fclean all clean re
