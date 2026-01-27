NAME = push_swap
NAME_B = checker

HDR = push_swap.h
HDR_B = checker_bonus.h

CC = cc
CFLAGS = -Werror -Wall -Wextra
AR = ar rcs


PS_ARCHIVE = push_swap.a
LIBFT = libft/libft.a


SRC_MAIN	= push_swap.c
SRC_MAIN_B	= checker_bonus.c checker_utils_bonus.c

SRC =\
actions.c\
actions_caller_p1.c\
actions_caller_p2.c\
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

all: Libft $(NAME) 

bonus: Libft $(NAME_B)

$(NAME): $(SRC_MAIN) $(PS_ARCHIVE) $(LIBFT)
	@echo "\n[ Compiling... ]"
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_B): $(HDR_B) $(SRC_MAIN_B) $(PS_ARCHIVE) $(LIBFT)
	@echo "\n[ Compiling bonus... ]"
	$(CC) $(CFLAGS) -o $@ -I $^

Libft : 
	@echo "\n[ Upating Libft... ]"
	make all bonus -C ./libft CC="cc -g3"

$(PS_ARCHIVE):  $(OBJ) 
	@echo "\n[ Updated Push_swap Archive ]"

%.o: %.c $(HDR)
	$(CC) -c $(CFLAGS) $<
	$(AR) $(PS_ARCHIVE) $@

clean:
	rm -f $(OBJ) $(OBJ_MAIN_B) $(PS_ARCHIVE)
	make fclean -C ./libft

fclean: clean
	rm -f $(NAME) $(NAME_B)

re: fclean all

.PHONY: fclean all clean re Libft
