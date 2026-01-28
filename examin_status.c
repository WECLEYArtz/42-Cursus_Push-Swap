/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   examin_status.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmounsi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:49:08 by ahmounsi          #+#    #+#             */
/*   Updated: 2026/01/15 23:49:08 by ahmounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

short	examin_status(t_list *stack)
{
	int		prev_val;

	if (!stack)
		return (1);
	prev_val = *(int *)(stack->content);
	stack = stack->next;
	while (stack)
	{
		if (*(int *)(stack->content) < prev_val)
			return (0);
		prev_val = *(int *)(stack->content);
		stack = stack->next;
	}
	return (1);
}
