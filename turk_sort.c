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
		push(stacks.a, stacks.b, "a");
		stack_len.a++;
		stack_len.b--;
	}
}

static void	apply_instr(t_stacks stacks, t_stack_len stack_len, size_t moves,
		size_t index)
{

	// [ Potential Solution ]
	// if ((moves > stack_len.a / 2 && index > stack_len.b / 2)
	// 	|| (moves < stack_len.a / 2 && index < stack_len.b / 2))
	// 	optimise_instr();
	if (moves > stack_len.a / 2)
	{
		moves = stack_len.a - moves;
		while (moves--)
			rrotate(stacks.a, "a");
	}
	else
		while (moves--)
			rotate(stacks.a, "a");
	if (index > stack_len.b / 2)
	{
		index = stack_len.b - index;
		while (index--)
			rrotate(stacks.b, "b");
	}
	else
		while (index--)
			rotate(stacks.b, "b");
}

static	void	update_cheapest_node(t_cheapest *cheapest_node,
		t_stack_len stack_len, size_t moves, size_t index)
{
	if (moves > stack_len.a / 2)
		moves = stack_len.a - moves;
	if (index > stack_len.b / 2)
		index = stack_len.b - index;
	if (moves + index < cheapest_node->cost)
	{
		cheapest_node->cost = moves + index;
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
	size_t				moves;
	static t_cheapest	cheapest; // allocate instaed, stack will keep wrong data, cant easielly reset
	if(index == 0)
	{
		cheapest.index = 0; 
		cheapest.cost = LONG_MAX; 
		cheapest.applied = 0;
	}

	moves = 0;
	if (work_node)
	{
		moves = get_moves_to_target(*stacks.a, *(int *)(work_node->content));
		update_cheapest_node(&cheapest, stack_len, moves, index);
		if(!cheapest.cost)
			return;
		turk_rec(index+1, stacks, work_node->next, stack_len);
	}
	if (cheapest.index == index && !cheapest.applied)
	{
		apply_instr(stacks, stack_len, moves, index);
		cheapest.applied = 1;
	}
}


