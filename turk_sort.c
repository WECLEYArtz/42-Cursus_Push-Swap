#include "libft/libft.h"
#include "push_swap.h"

static void	turk_rec(size_t index,
		t_stacks stacks, t_list *work_node, t_stack_len stack_len);

void	turk_sort(t_stacks stacks)
{
	t_stack_len	stack_len;

	stack_len.a = ft_lstsize(*stacks.a);
	stack_len.b = ft_lstsize(*stacks.b);
	while (*stacks.b)
	{
		turk_rec(0 ,stacks, *stacks.b, stack_len);
		p(stacks.a, stacks.b, "a");
		stack_len.a++;
		stack_len.b--;
	}
}


static void	apply_instr(t_stacks stacks, t_mvs_rots rot)
{
	void (*rotfunc[2])(t_list **stack_p, char *act_name);

	rotfunc[0] = r;
	rotfunc[0] = rr;
	if(rot.rev_direct_a && rot.rev_direct_b)
	{
		while(rot.moves_a && rot.rev_direct_b)
			rrr_(stacks);
	}
	else if(!rot.rev_direct_a && !rot.rev_direct_b)
	{
		while( rot.moves_a && rot.rev_direct_b)
			rr__(stacks);
	}
	while(rot.moves_a--)
		rotfunc[rot.rev_direct_a](stacks.a, "a");
	while(rot.moves_b--)
		rotfunc[rot.rev_direct_b](stacks.b, "b");
}

static	void	update_cheapest(t_cheapest *cheapest_node, t_mvs_rots *rot,
		t_stack_len stack_len, size_t index)
{
	if (rot->moves_a > stack_len.a / 2)
	{
		rot->moves_a = stack_len.a - rot->moves_a;
		rot->rev_direct_a = 1;
	}
	else
		rot->rev_direct_a = 0;
	if (rot->moves_b > stack_len.b / 2)
	{
		rot->moves_b = stack_len.b - rot->moves_b;
		rot->rev_direct_b = 1;
	}
	else
		rot->rev_direct_b = 0;
	if (rot->moves_a + rot->moves_b < cheapest_node->cost)
	{
		cheapest_node->cost = rot->moves_a + rot->moves_b;
		cheapest_node->index = index;
	}
}

/*	[Forward:]
 *	Recursively loop on each node in stack b
 *	save the cost (instructions in stack a(moves) and b(index)) in order to place the current
 *	node in b, in stack a, update the cheapest cost on the proccess.
 *
 *	[Backward:]
 *	Look for then apply instructions for the registered index with cheapest cost,
 *	then update the "applied" flag.
 *
 * */
static void	turk_rec(size_t index, t_stacks stacks, t_list *work_node, t_stack_len stack_len)
{

	t_mvs_rots	rots;
	static t_cheapest	cheapest; // allocate instaed, stack will keep wrong data, cant easielly reset

	if(index == 0)
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
		if(!cheapest.cost)
			return;
		turk_rec(index+1, stacks, work_node->next, stack_len);
	}
	if (cheapest.index == index && !cheapest.applied)
	{
		apply_instr(stacks, rots);
		cheapest.applied = 1;
	}
}
