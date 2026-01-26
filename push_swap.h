/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmounsi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:47:13 by ahmounsi          #+#    #+#             */
/*   Updated: 2026/01/22 00:30:52 by ahmounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void		r(t_list **stack_p, char *act_name, short verbal);
void		rr(t_list **stack_p, char *act_name, short verbal);
void		p(t_list **stack_dst_p, t_list **stack_src_p, char *act_name,
				short verbal);
void		s(t_list **stack_p, char *stack_name, short verbal);
void		ss_(t_stacks stacks, short verbal);
void		rr__(t_stacks stacks, short verbal);
void		rrr_(t_stacks stacks, short verbal);

// Actions
void		rotate(t_list **stack_p);
void		revrotate(t_list **stack_p);
void		push(t_list **stack_dst_p, t_list **stack_src_p);
void		swap(t_list **stack_p);

// Getters
t_list		*get_list(char **argv);
size_t		get_target_moves(t_list *stack_a, int target);

// Helpers
void		init_stacks(t_stacks stacks);
short		examin_status(t_list **stack);
void		hard_sort(t_list **stack_a);
void		final_sort(t_list **stack_a, size_t stack_len_a);
int			ft_atoi_custom(char **argv, short *success);


#endif
