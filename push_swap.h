#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdlib.h>

typedef struct s_line{
	int value;
	void *next;
} t_line;

t_list *get_list(char **argv);

void rotate(t_list **stack_p, char *act_name);
void rrotate(t_list **stack_p, char *act_name);
void push(t_list **stack_dst_p, t_list **stack_src_p, char *act_name);
#endif
