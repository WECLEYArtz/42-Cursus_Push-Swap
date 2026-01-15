/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmounsi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:05:19 by ahmounsi          #+#    #+#             */
/*   Updated: 2026/01/15 23:05:25 by ahmounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **stack_dst_p, t_list **stack_src_p)
{
	t_list	*tmp;

	if (!stack_src_p || !*stack_src_p)
		return ;
	tmp = (*stack_src_p)->next;
	ft_lstadd_front(stack_dst_p, *stack_src_p);
	*stack_src_p = tmp;
}

void	rotate(t_list **stack_p)
{
	t_list	*newback;
	t_list	*newhead;

	if (!stack_p || !(*stack_p) || !(*stack_p)->next)
		return ;
	newback = *stack_p;
	newhead = (*stack_p)->next;
	ft_lstadd_back(stack_p, *stack_p);
	newback->next = NULL;
	*stack_p = newhead;
}

void	revrotate(t_list **stack_p)
{
	t_list	*last_node;
	t_list	*last_node_depth1;

	if (!stack_p || !(*stack_p) || !(*stack_p)->next)
		return ;
	last_node = *stack_p;
	last_node_depth1 = *stack_p;
	while (1)
	{
		last_node = last_node->next;
		if (!(last_node->next))
			break ;
		last_node_depth1 = last_node;
	}
	last_node_depth1->next = NULL;
	last_node->next = *stack_p;
	*stack_p = last_node;
}

void	swap(t_list **stack_p)
{
	t_list	*tmp;

	if (!stack_p || !(*stack_p) || !(*stack_p)->next)
		return ;
	tmp = *stack_p;
	*stack_p = (*stack_p)->next;
	tmp->next = (*stack_p)->next;
	(*stack_p)->next = tmp;
}
