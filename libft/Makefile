NAME = libft.a

HDR = libft.h
HDR_GNL = get_next_line/get_next_line.h

CC = cc
CFLAGS = -c -Werror -Wall -Wextra

AR = ar rcs

SRC =\
ft_isdigit.c \
ft_strncmp.c \
ft_memcpy.c \
ft_bzero.c
SRC_GNL=\
get_next_line/get_next_line.c\
get_next_line/get_next_line_utils.c
SRC_B=\
ft_lstadd_back_bonus.c \
ft_lstadd_front_bonus.c \
ft_lstclear_bonus.c \
ft_lstdelone_bonus.c \
ft_lstlast_bonus.c \
ft_lstnew_bonus.c \
ft_lstsize_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_GNL = $(SRC_GNL:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

all: $(NAME)

bonus: $(OBJ_B)

$(NAME): $(OBJ) $(OBJ_GNL)

get_next_line%.o: get_next_line%.c $(HDR_GNL)
	$(CC) $(CFLAGS) -o $@ $<
	$(AR) $(NAME) $@

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -o $@ $<
	$(AR) $(NAME) $@


clean: 
	rm -f $(OBJ) $(OBJ_B) $(OBJ_GNL)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean all clean re
