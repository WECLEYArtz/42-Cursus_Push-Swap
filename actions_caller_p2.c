/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_caller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmounsi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:05:19 by ahmounsi          #+#    #+#             */
/*   Updated: 2026/01/15 23:48:30 by ahmounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p(t_list **stack_dst_p, t_list **stack_src_p, char *stack_name,
		short verbal)
{
	push(stack_dst_p, stack_src_p);
	if (!verbal)
		return ;
	write(1, "p", 1);
	write(1, stack_name, 1);
	write(1, "\n", 1);
}

void	r(t_list **stack_p, char *stack_name, short verbal)
{
	rotate(stack_p);
	if (!verbal)
		return ;
	write(1, "r", 1);
	write(1, stack_name, 1);
	write(1, "\n", 1);
}

void	rr(t_list **stack_p, char *stack_name, short verbal)
{
	revrotate(stack_p);
	if (!verbal)
		return ;
	write(1, "rr", 2);
	write(1, stack_name, 1);
	write(1, "\n", 1);
}

void	s(t_list **stack_p, char *stack_name, short verbal)
{
	swap(stack_p);
	if (!verbal)
		return ;
	write(1, "s", 1);
	write(1, stack_name, 1);
	write(1, "\n", 1);
}
