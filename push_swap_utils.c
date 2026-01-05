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

void apply_instr(t_list **stack_a, t_list **stack_b, size_t moves, size_t index)
{
	size_t stack_a_len = ft_lstsize(stack_a);

}

short	update_cheapest_node(t_cheapest_node cheapest_node, t_stack_len stack_len,
					size_t moves, size_t index)
{
		if (moves < stack_len.a/2)
			moves = stack_len.a - moves;
		if (index < stack_len.b/2)
			index = stack_len.b - index;
		if (moves + index < cheapest_node.cost)
		{
			cheapest_node.index = index;
			return 1;
		}
		return 0;
}


static void turk_rec(t_list **stack_a, t_list **stack_b, t_list *work_node, t_stack_len stack_len)
{
	size_t	moves;
	static size_t	index = 0;
	static t_cheapest_node cheapest_node;

	moves = 0;
	if(work_node)
	{
		moves = get_moves_to_target(*stack_a, *(int*)(work_node->content));
		update_cheapest_node(cheapest_node, stack_len, moves, index++);
		turk_rec(stack_a, stack_b, work_node->next, stack_len);
	}
	if (cheapest_node.index == index && !cheapest_node.applied)
	{
		apply_instr(stack_a, stack_b, moves, index);
		cheapest_node.applied = 1;
	}
}

void turk_sort(t_list **stack_a, t_list **stack_b)
{
	t_stack_len stack_len;

	stack_len.a = ft_lstsize(*stack_a);
	stack_len.b = ft_lstsize(*stack_b);
	while(stack_b)
	{
		turk_rec(stack_a, stack_b, *stack_b, stack_len);
		push(stack_a, stack_b, "pa\n");
		stack_len.a++;
		list_stacks(*stack_a, *stack_b);
	}
}
