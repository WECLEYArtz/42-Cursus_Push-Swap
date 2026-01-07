#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft/libft.h"
#include <stddef.h>
#include <stdlib.h>

// +~~~~~~~~~~~~~~~~~~~~~~~~~+
// +=========================+
// |  GET_MOVES_TO_TARGET()  |
// +=========================+
typedef struct s_cmp_vars {
	int		min;
	int		target;
	size_t	iterations;
	size_t	result;

} t_cmp_vars;

typedef struct s_mv_vars {
	size_t	current;
	short	final;
} t_mv_vars;


// +=========================+
// |        TURK_SORT        |
// +=========================+
typedef struct s_cheapest {
	size_t	index;
	size_t	cost;
	short	applied;
} t_cheapest;

typedef struct s_stack_len {
	size_t	a;
	size_t	b;
} t_stack_len;

typedef struct s_stacks {
	t_list	**a;
	t_list	**b;
} t_stacks;
// +~~~~~~~~~~~~~~~~~~~~~~~~~+


// Main Functions
void turk_sort(t_stacks stacks);

// Actions
void	rotate(t_list **stack_p, char *act_name);
void	rrotate(t_list **stack_p, char *act_name);
void	push(t_list **stack_dst_p, t_list **stack_src_p, char *act_name);
void	swap(t_list **stack_p, char *stack_name);

// Helpers
void	hard_sort(t_list **st_a);
void	init_stacks(t_stacks stacks);
size_t	get_moves_to_target(t_list *stack, int target);
t_list *get_list(char **argv);

#endif
