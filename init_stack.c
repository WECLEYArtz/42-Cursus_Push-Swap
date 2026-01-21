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

static void	push_two(t_stacks stacks, size_t *stack_size, int *new_big)
{
	short	first_two;

	first_two = 2;
	while (*stack_size > 3 && first_two--)
	{
		p(stacks.b, stacks.a, "b", 1);
		(*stack_size)--;
		if (*(int *)(*stacks.b)->content > *new_big)
			*new_big = *(int *)((*stacks.b)->content);
	}
}

static void	push_till_three(t_stacks stacks, size_t stack_size, int new_big)
{
	while (stack_size > 3)
	{
		p(stacks.b, stacks.a, "b", 1);
		stack_size--;
		if (*(int *)(*stacks.b)->content > *(int *)((*stacks.b)->next->content))
			new_big = *(int *)((*stacks.b)->next->content);
		else if (*(int *)(*stacks.b)->content < new_big / 2)
			r(stacks.b, "b", 1);
	}
}

void	init_stacks(t_stacks stacks)
{
	size_t	stack_size;
	int		new_big;

	stack_size = ft_lstsize(*(stacks.a));
	if (stack_size > 3)
	{
		new_big = INT_MIN;
		push_two(stacks, &stack_size, &new_big);
		push_till_three(stacks, stack_size, new_big);
	}
	hard_sort(stacks.a);
}
