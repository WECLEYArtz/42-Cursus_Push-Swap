#include "libft/libft.h"
#include "push_swap.h"
#include <stddef.h>

/*
*/ 

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
		moves = get_moves_to_target(*stack_a, *(int*)(work_node->content))
			+ index;
		index++;
		turk_rec(stack_a, stack_b, work_node->next);
	}
	if (moves == cheapest_cost)

}

void turk_sort(stack_a, stack_b)
{

}
