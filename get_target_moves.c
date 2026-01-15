/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmounsi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:05:19 by ahmounsi          #+#    #+#             */
/*   Updated: 2026/01/15 23:48:30 by ahmounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

t_cmp_vars	init_cmp_vars(int min, int target)
{
	t_cmp_vars	cmp;

	cmp.min = min;
	cmp.target = target;
	cmp.iterations = 0;
	cmp.result = 0;
	return (cmp);
}

static void	update_for_min(t_list **stack, t_cmp_vars *cmp)
{
	int	value;

	value = *(int *)((*stack)->content);
	if (value < cmp->min || value > cmp->target)
	{
		cmp->min = value;
		cmp->result = cmp->iterations;
	}
	cmp->iterations++;
	*stack = (*stack)->next;
}

static void	update_for_target(t_list **stack, t_cmp_vars *cmp)
{
	int	value;

	value = *(int *)((*stack)->content);
	if (value < cmp->min && value > cmp->target)
	{
		cmp->min = value;
		cmp->result = cmp->iterations;
	}
	cmp->iterations++;
	*stack = (*stack)->next;
}

/*
 *	Lookup the best position for "target" in "stack",
 *	Return the amount of rotations to get the value,
 *	(returns only for none reversed rotation)
 *
 * */
size_t	get_target_moves(t_list *stack_a, int target)
{
	t_cmp_vars	cmps;

	if (!stack_a || !(stack_a->content))
		return (0);
	cmps = init_cmp_vars(*(int *)(stack_a->content), target);
	while (stack_a)
	{
		update_for_min(&stack_a, &cmps);
		if (cmps.min > target)
			break ;
	}
	while (stack_a)
		update_for_target(&stack_a, &cmps);
	return (cmps.result);
}
