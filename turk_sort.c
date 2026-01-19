/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmounsi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:05:19 by ahmounsi          #+#    #+#             */
/*   Updated: 2026/01/18 14:16:38 by ahmounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	optimise_rots(t_mvs_rots *rots, t_stack_len stack_len)
{
	if (rots->moves_a > stack_len.a / 2)
	{
		rots->moves_a = stack_len.a - rots->moves_a;
		rots->rev_direct_a = 1;
	}
	else
		rots->rev_direct_a = 0;
	if (rots->moves_b > stack_len.b / 2)
	{
		rots->moves_b = stack_len.b - rots->moves_b;
		rots->rev_direct_b = 1;
	}
	else
		rots->rev_direct_b = 0;
}

static void	apply_instr(t_stacks stacks, t_mvs_rots rot)
{
	void	(*rotfunc[2])(t_list **stack_p, char *act_name);
	void	(*mutual_rotfunc[2])(t_stacks stacks);

	rotfunc[0] = r;
	rotfunc[1] = rr;
	mutual_rotfunc[0] = rr__;
	mutual_rotfunc[1] = rrr_;
	if (rot.rev_direct_a == rot.rev_direct_b)
	{
		while (rot.moves_a && rot.moves_b)
		{
			mutual_rotfunc[rot.rev_direct_a](stacks);
			rot.moves_a--;
			rot.moves_b--;
		}
	}
	while (rot.moves_a--)
	{
		rotfunc[rot.rev_direct_a](stacks.a, "a");
	}
	while (rot.moves_b--)
	{
		rotfunc[rot.rev_direct_b](stacks.b, "b");
	}
}

static void	update_cheapest(t_cheapest *cheapest_node, t_mvs_rots *rot,
		size_t index)
{
	size_t	new_cost;

	if (rot->rev_direct_a == rot->rev_direct_b)
	{
		if (rot->moves_a > rot->moves_b)
			new_cost = rot->moves_a;
		else
			new_cost = rot->moves_b;
	}
	else
		new_cost = rot->moves_a + rot->moves_b;
	if (new_cost < cheapest_node->cost)
	{
		cheapest_node->cost = new_cost;
		cheapest_node->index = index;
	}
}

static void	turk_rec(t_stacks stacks, t_stack_len stacks_len, t_list *stack,
		size_t index)
{
	t_mvs_rots			rots;
	static t_cheapest	cheapest;

	if (index == 0)
	{
		cheapest.index = 0;
		cheapest.cost = LONG_MAX;
		cheapest.applied = 0;
	}
	if (stack)
	{
		rots.moves_a = get_target_moves(*stacks.a, *(int *)(stack->content));
		rots.moves_b = index;
		optimise_rots(&rots, stacks_len);
		update_cheapest(&cheapest, &rots, index);
		if (!cheapest.cost)
			return ;
		turk_rec(stacks, stacks_len, stack->next, index + 1);
	}
	if (cheapest.index == index && !cheapest.applied)
	{
		apply_instr(stacks, rots);
		cheapest.applied = 1;
	}
}

void	turk_sort(t_stacks stacks)
{
	t_stack_len	stacks_len;

	stacks_len.a = ft_lstsize(*stacks.a);
	stacks_len.b = ft_lstsize(*stacks.b);
	while (*stacks.b)
	{
		turk_rec(stacks, stacks_len, *stacks.b, 0);
		p(stacks.a, stacks.b, "a");
		stacks_len.a++;
		stacks_len.b--;
	}
	final_sort(stacks.a, stacks_len.a);
}
