/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmounsi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:05:19 by ahmounsi          #+#    #+#             */
/*   Updated: 2026/01/18 14:16:20 by ahmounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_arr(int *arr, t_list *stack_a)
{
	while (stack_a)
	{
		*arr++ = *(int *)stack_a->content;
		stack_a = stack_a->next;
	}
}

void	hard_sort(t_list **stack_a)
{
	int	vals[3];

	if (!(*stack_a)->next->next)
	{
		s(stack_a, "a");
		return ;
	}
	fill_arr(vals, *stack_a);
	if (vals[0] < vals[1] && vals[1] < vals[2] && vals[0] < vals[2])
		return ;
	if (vals[0] > vals[1] && vals[1] < vals[2] && vals[0] < vals[2])
		s(stack_a, "a");
	if (vals[0] > vals[1])
	{
		r(stack_a, "a");
		if (vals[1] > vals[2])
			s(stack_a, "a");
	}
	else if (vals[0] < vals[1])
	{
		rr(stack_a, "a");
		if (vals[0] < vals[2])
			s(stack_a, "a");
	}
}
