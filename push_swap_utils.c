#include "libft/libft.h"
#include "push_swap.h"
#include <stddef.h>

// === REMOVE LATER ===
#include "stdio.h"
#include "push_swap.debuggers.h"
// ====================

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

static void turk_rec(t_list **stack_a, t_list **stack_b, t_list *work_node, size_t stack_len)
{
	size_t	moves;
	static size_t	index = 0;
	static size_t	cheapest_cost = 0;
	static short	instr_applied = 0;

	moves = 0;
	if(work_node)
	{
		moves = get_moves_to_target(*stack_a, *(int*)(work_node->content));
		if (moves < stack_len/2)
		{
			if (stack_len - moves < cheapest_cost)
				cheapest_cost = moves;
		}
		else
			if (moves < cheapest_cost)
				cheapest_cost = moves;
		index++;
		turk_rec(stack_a, stack_b, work_node->next, stack_len);
	}
	if (moves == cheapest_cost && !instr_applied)
	{
		if (moves < stack_len/2) 
		{
			moves = stack_len - moves;
			while(moves--)
				rrotate(stack_b, "rrb\n");
		}
		else
			while(moves--)
				rotate(stack_b, "rb\n");
		instr_applied = 1;
		index--;

		// printf("applying chepaset moves :%ld for digit %d",
		// 	moves ,*(int*)(work_node->content));
	}
}

void turk_sort(t_list **stack_a, t_list **stack_b)
{
	size_t stack_a_len;

	stack_a_len = 3;
	while(stack_b)
	{
		turk_rec(stack_a, stack_b, *stack_b, stack_a_len);
		push(stack_a, stack_b, "pb\n");
		stack_a_len++;
		list_stacks(*stack_a, *stack_b);
	}
}
