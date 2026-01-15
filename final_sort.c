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

#include "libft/libft.h"
#include "push_swap.h"

void	final_sort(t_list **stack_a, size_t stack_len_a)
{
	t_list	*work_node;
	size_t	moves;

	moves = get_moves_break(*stack_a);
	work_node = *stack_a;
	if (moves > stack_len_a / 2)
	{
		moves = stack_len_a - moves;
		while (moves--)
			rr(stack_a, "a");
	}
	else
		while (moves--)
			r(stack_a, "a");
}

size_t	get_moves_break(t_list *stack_a)
{
	int		old_value;
	size_t	moves;

	old_value = *(int *)(stack_a->content);
	stack_a = stack_a->next;
	moves = 1;
	while (stack_a)
	{
		if (old_value > *(int *)(stack_a->content))
			return (moves);
		old_value = *(int *)(stack_a->content);
		stack_a = stack_a->next;
		moves++;
	}
	return (0);
}
