#include "libft/libft.h"
#include "push_swap.h"

static short	optimise_rots(size_t *moves, size_t stack_len)
{
	if (*moves > stack_len / 2)
	{
		*moves = stack_len - *moves;
		return (1);
	}
	return (0);
}

static void	apply_mutual_rots(t_stacks stacks, t_mvs_rots *rot,
		void f(t_stacks stacks))
{
	while (rot->moves_a && rot->moves_b)
	{
		f(stacks);
		rot->moves_a--;
		rot->moves_b--;
	}
}

static void	apply_instr(t_stacks stacks, t_mvs_rots rot)
{
	void	(*rotfunc[2])(t_list * *stack_p, char *act_name);

	rotfunc[0] = r;
	rotfunc[1] = rr;
	if (rot.rev_direct_a && rot.rev_direct_b)
	{
		apply_mutual_rots(stacks, &rot, rrr_);
	}
	else if (!rot.rev_direct_a && !rot.rev_direct_b)
	{
		apply_mutual_rots(stacks, &rot, rr__);
	}
	while (rot.moves_a--)
		rotfunc[rot.rev_direct_a](stacks.a, "a");
	while (rot.moves_b--)
		rotfunc[rot.rev_direct_b](stacks.b, "b");
}

static void	update_cheapest(t_cheapest *cheapest_node, t_mvs_rots *rot,
		t_stack_len stack_len, size_t index)
{
	size_t	new_cost;

	rot->rev_direct_a = optimise_rots(&(rot->moves_a), stack_len.a);
	rot->rev_direct_b = optimise_rots(&(rot->moves_b), stack_len.b);
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

/*	[Forward:]
 *
 *	Recursively loop on each node in stack b

 *	save the cost (instructions in stack a(moves) and b(index))
 *	in order to place the current
 *	node in b, in stack a, update the cheapest cost on the proccess.
 *
 *	[Backward:]
 *	Find then apply instructions for the cheapest cost index,
 *	then update the "applied" flag.
 *
 * */
static void	turk_rec(size_t index, t_stacks stacks, t_list *work_node,
		t_stack_len stack_len)
{
	t_mvs_rots			rots;
	static t_cheapest	cheapest;

	if (index == 0)
	{
		cheapest.index = 0;
		cheapest.cost = LONG_MAX;
		cheapest.applied = 0;
	}
	if (work_node)
	{
		rots.moves_a = get_moves(*stacks.a, *(int *)(work_node->content));
		rots.moves_b = index;
		update_cheapest(&cheapest, &rots, stack_len, index);
		if (!cheapest.cost)
			return ;
		turk_rec(index + 1, stacks, work_node->next, stack_len);
	}
	if (cheapest.index == index && !cheapest.applied)
	{
		apply_instr(stacks, rots);
		cheapest.applied = 1;
	}
}

void	turk_sort(t_stacks stacks)
{
	t_stack_len	stack_len;

	stack_len.a = ft_lstsize(*stacks.a);
	stack_len.b = ft_lstsize(*stacks.b);
	while (*stacks.b)
	{
		turk_rec(0, stacks, *stacks.b, stack_len);
		p(stacks.a, stacks.b, "a");
		stack_len.a++;
		stack_len.b--;
	}
	final_sort(stacks.a, stack_len.a);
}
