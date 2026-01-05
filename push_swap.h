#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/libft.h"
#include <stddef.h>
#include <stdlib.h>

typedef struct s_cmp_vars {
	size_t	node_index;
	int		min;
	int		target;
} t_cmp_vars;


typedef struct s_mv_vars {
	size_t	moves_count;
	short	moves_ret;
} t_mv_vars;

typedef struct s_cheapest_reg {
	size_t	index;
	size_t	cost;
	short	applied;
} t_cheapest_node;

typedef struct s_stack_len {
	size_t	a;
	size_t	b;
} t_stack_len;

t_list *get_list(char **argv);

// Actions
void	rotate(t_list **stack_p, char *act_name);
void	rrotate(t_list **stack_p, char *act_name);
void	push(t_list **stack_dst_p, t_list **stack_src_p, char *act_name);

// Helpers
short	init_stacks(t_list **stack_a , t_list **stack_b);
size_t	get_moves_to_target(t_list *stack, int target);

#endif
