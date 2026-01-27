/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmounsi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:49:24 by ahmounsi          #+#    #+#             */
/*   Updated: 2026/01/18 14:16:26 by ahmounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_two(t_stacks stacks, size_t *stack_size)
{
	short	first_two;

	first_two = 2;
	while (*stack_size > 3 && first_two--)
	{
		p(stacks.b, stacks.a, "b", 1);
		(*stack_size)--;
	}
}

static void	push_till_three(t_stacks stacks, size_t stack_size)
{
	int mid_big = *(int *)(*stacks.b)->content * 0.5;
	while (stack_size > 3)
	{
		p(stacks.b, stacks.a, "b", 1);
		stack_size--;
		if (*(int *)(*stacks.b)->content > *(int *)((*stacks.b)->next->content))
			mid_big = *(int *)((*stacks.b)->next->content) * 0.5;
		else if (*(int *)(*stacks.b)->content < mid_big)
			r(stacks.b, "b", 1);
	}
}

void	init_stacks(t_stacks stacks)
{
	size_t	stack_size;

	stack_size = ft_lstsize(*(stacks.a));
	if (stack_size > 3)
	{
		push_two(stacks, &stack_size);
		push_till_three(stacks, stack_size);
	}
	hard_sort(stacks.a);
}
