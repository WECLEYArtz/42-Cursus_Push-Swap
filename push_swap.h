#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stddef.h>
# include <stdlib.h>

// +~~~~~~~~~~~~~~~~~~~~~~~~~+
// +=========================+
// |  GET_MOVES_TO_TARGET()  |
// +=========================+
typedef struct s_cmp_vars
{
	int		min;
	int		target;
	size_t	iterations;
	size_t	result;

}			t_cmp_vars;

// +=========================+
// |        TURK_SORT        |
// +=========================+
typedef struct s_cheapest
{
	size_t	index;
	size_t	cost;
	short	applied;
}			t_cheapest;

typedef struct s_stack_len
{
	size_t	a;
	size_t	b;
}			t_stack_len;

typedef struct s_stacks
{
	t_list	**a;
	t_list	**b;
}			t_stacks;

typedef struct s_mvs_rots
{
	size_t	moves_b;
	short	rev_direct_a;
	size_t	moves_a;
	short	rev_direct_b;
}			t_mvs_rots;
// +~~~~~~~~~~~~~~~~~~~~~~~~~+

// Main Functions
void		turk_sort(t_stacks stacks);

// Actions Callers
void		r(t_list **stack_p, char *act_name);
void		rr(t_list **stack_p, char *act_name);
void		p(t_list **stack_dst_p, t_list **stack_src_p, char *act_name);
void		s(t_list **stack_p, char *stack_name);
void		rr__(t_stacks stacks);
void		rrr_(t_stacks stacks);

// Actions
void		rotate(t_list **stack_p);
void		revrotate(t_list **stack_p);
void		push(t_list **stack_dst_p, t_list **stack_src_p);
void		swap(t_list **stack_p);

// Getters
t_list		*get_list(char **argv);
size_t		get_moves(t_list *stack_a, int target);

// Helpers
int			ft_atoi_check(const char *str, short *overflowed);
void		hard_sort(t_list **stack_a);
void		final_sort(t_list **stack_a, size_t stack_len_a);

// Hacky Helpers
void		update_for_min(t_list **stack, t_cmp_vars *cmp);
t_cmp_vars	init_cmp_vars(int min, int target);

#endif
