#include "libft/libft.h"
#include "push_swap.h"
#include <stddef.h>

/*
*/ 
size_t get_moves_to_target(t_list *stack, int target)
{
	if(!stack || !(stack->content))
		return 0;
	size_t	moves;
	size_t	ret_moves;
	int		min = *(int *)(stack->content);
	moves = 0;
	ret_moves = 0;
	while(stack)
	{
		if(*(int *)(stack -> content) < min)
		{
			min = *(int *)(stack -> content);
			ret_moves = moves;
		}
		stack = stack->next;
		moves++;
	}
	return ret_moves;

	// find moves count to smallest bigger
	// maybe the same as trying to find the smallest value, but override only if bigger than target
}

short	init_stacks(t_list **stack_a , t_list **stack_b){
	size_t stack_size = ft_lstsize(*stack_a);
	stack_size -= 3;
	if(stack_size > 3)
	{
		while(stack_size--)
			push(stack_b, stack_a, "pb\n");
		return 0;
	}
	else
		return stack_size;
}

// NEEDED DATA:
// stacks
// instructions count each call
// static value of least amount of instruction (to compare with next value).
// value of instructions count for current stack (applied on current node).
// static variable flag for wether instructions were applied.

static void turk_rec(t_list **stack_a, t_list **stack_b, t_list *work_node)
{
	static size_t	index = 0;
	static short	is_applied = 0;
	static size_t	cheapest_cost = 0;
	size_t moves;

	moves = 0;
	if(work_node)
	{
		moves = get_moves_to_target(work_node, *(int*)(work_node->content))
			+ index;
		index++;
		turk_rec(stack_a, stack_b, work_node->next);
	}
	if (moves == cheapest_cost)

}

void turk_sort(stack_a, stack_b)
{

}
