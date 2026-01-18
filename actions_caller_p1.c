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


void	rr__(t_stacks stacks)
{
	rotate(stacks.a);
	rotate(stacks.b);
	write(1, "rr\n", 3);
}

void	rrr_(t_stacks stacks)
{
	revrotate(stacks.a);
	revrotate(stacks.b);
	write(1, "rrr\n", 4);
}

void	ss_(t_stacks stacks)
{
	swap(stacks.a);
	swap(stacks.b);
	write(1, "ss\n", 3);
}
