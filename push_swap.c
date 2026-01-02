// ====[ DEBUGGERS ]====
#include "push_swap.debuggers.h"
// =====================
#include "push_swap.h"
#include "libft/libft.h"
#include <unistd.h>


size_t get_moves_to_min(t_list *stack)
{
	if(!stack || !(stack->content))
		return 0;
	size_t	moves;
	size_t	ret_moves;
	int		min = *(int *)(stack->content);
	stack = stack->next;
	moves = 1;
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
}


int main(int argc, char **argv)
{
	if(argc < 2)
		return (0);
	t_list *stack_a = get_list(argv+1);
	t_list *stack_b = NULL;
	size_t moves_to_max;
	size_t stack_len;

	stack_len = ft_lstsize(stack_a);
	while(stack_len)
	{
		// list_stacks(stack_a, stack_b);
		moves_to_max = get_moves_to_min(stack_a);
		if(moves_to_max < stack_len/2)
			while(moves_to_max--)
				rotate(&stack_a, "ra\n");
		else
		{
			moves_to_max = stack_len - moves_to_max;
			while(moves_to_max--)
				rrotate(&stack_a, "rra\n");
		}
		push(&stack_b, &stack_a, "pb\n");
		stack_len--;
	}
	while(stack_b)
		push(&stack_a, &stack_b, "pa\n");
	// list_stacks(stack_a, stack_b);
	ft_lstclear(&stack_a, free);
}
