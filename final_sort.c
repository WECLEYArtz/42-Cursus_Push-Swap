/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmounsi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:05:19 by ahmounsi          #+#    #+#             */
/*   Updated: 2026/01/15 23:48:30 by ahmounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	get_incr_sqnce_moves(t_list *stack_a)
{
	int		previous;
	size_t	moves;

	previous = *(int *)(stack_a->content);
	stack_a = stack_a->next;
	moves = 1;
	while (stack_a)
	{
		if (previous > *(int *)(stack_a->content))
			return (moves);
		previous = *(int *)(stack_a->content);
		stack_a = stack_a->next;
		moves++;
	}
	return (0);
}

void	final_sort(t_list **stack_a, size_t stack_len_a)
{
	size_t	moves;

	moves = get_incr_sqnce_moves(*stack_a);
	if (moves > stack_len_a / 2)
	{
		moves = stack_len_a - moves;
		while (moves--)
			rr(stack_a, "a", 1);
	}
	else
		while (moves--)
			r(stack_a, "a", 1);
}
