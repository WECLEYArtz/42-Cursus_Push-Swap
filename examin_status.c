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

short	examin_status(t_list **stack)
{
	t_list	*work_stack;
	int		prev_val;

	work_stack = *stack;
	if (!work_stack)
		return(1);
	prev_val = *(int *)(work_stack->content);
	work_stack = work_stack->next;
	while (work_stack)
	{
		if (*(int *)(work_stack->content) < prev_val)
			return(0) ;
		prev_val = *(int *)(work_stack->content);
		work_stack = work_stack->next;
	}
	ft_lstclear(stack, free);
	return(1);
}
