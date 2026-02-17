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
	void	(*rotfunc[2])(t_list **stack_p, char *act_name, short verbal);
	void	(*mutual_rotfunc[2])(t_stacks stacks, short verbal);

	rotfunc[0] = r;
	rotfunc[1] = rr;
	mutual_rotfunc[0] = rr__;
	mutual_rotfunc[1] = rrr_;
	if (rot.rev_direct_a == rot.rev_direct_b)
	{
		while (rot.moves_a && rot.moves_b)
		{
			mutual_rotfunc[rot.rev_direct_a](stacks, 1);
			rot.moves_a--;
			rot.moves_b--;
		}
	}
	while (rot.moves_a--)
	{
		rotfunc[rot.rev_direct_a](stacks.a, "a", 1);
	}
	while (rot.moves_b--)
	{
		rotfunc[rot.rev_direct_b](stacks.b, "b", 1);
	}
}

static void	update_cheapest(t_mvs_rots *rot_old, t_mvs_rots *rot_new)
{
	size_t	old_cost;
	size_t	new_cost;

	if (rot_new->rev_direct_a == rot_new->rev_direct_b)
	{
		if (rot_new->moves_a > rot_new->moves_b)
			new_cost = rot_new->moves_a;
		else
			new_cost = rot_new->moves_b;
	}
	else
		new_cost = rot_new->moves_a + rot_new->moves_b;
	if (rot_old->rev_direct_a == rot_old->rev_direct_b)
	{
		if (rot_old->moves_a > rot_old->moves_b)
			old_cost = rot_old->moves_a;
		else
			old_cost = rot_old->moves_b;
	}
	else
		old_cost = rot_old->moves_a + rot_old->moves_b;
	if (new_cost < old_cost)
		*rot_old = *rot_new;
}

static void	turk_sort_prepare_cheapest(t_stacks stacks, t_stack_len stacks_len)
{
	size_t		index;
	t_mvs_rots	rots;
	t_mvs_rots	rots_new;
	t_list		*b_element;

	b_element = *stacks.b;
	index = 0;
	rots.moves_a = get_target_moves(*stacks.a, *(int *)(b_element->content));
	rots.moves_b = index++;
	optimise_rots(&rots, stacks_len);
	b_element = b_element->next;
	while (b_element)
	{
		rots_new.moves_a = get_target_moves(*stacks.a,
				*(int *)(b_element->content));
		rots_new.moves_b = index;
		optimise_rots(&rots_new, stacks_len);
		update_cheapest(&rots, &rots_new);
		b_element = b_element->next;
		index++;
	}
	apply_instr(stacks, rots);
}

void	turk_sort(t_stacks stacks)
{
	t_stack_len	stacks_len;

	stacks_len.a = 3;
	stacks_len.b = ft_lstsize(*stacks.b);
	while (*stacks.b)
	{
		turk_sort_prepare_cheapest(stacks, stacks_len);
		p(stacks.a, stacks.b, "a", 1);
		stacks_len.a++;
		stacks_len.b--;
	}
	final_sort(stacks.a, stacks_len.a);
}
