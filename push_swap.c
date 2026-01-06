#include "push_swap.h"
#include "libft/libft.h"

// 49448 43638 5664 46265 39002\ 31767\ 48734\ 10533 2019 35284
int main(int argc, char **argv)
{
	if(argc < 2)
		return (1);
	t_list *stack_a = get_list(argv+1);
	t_list *stack_b = NULL;
	t_stacks stacks;

	stacks.a = &stack_a;
	stacks.b = &stack_b;
	if (init_stacks(&stack_a, &stack_b) == 0)
	{
		// list_stacks(stack_a, stack_b);
		turk_sort(stacks);
		// list_stacks(stack_a, stack_b);
	}
	ft_lstclear(&stack_a, free);
}

/*	Takes stack a and b to to push everything from a to b.
 *	Leaves 3 nodes in stack a.
 *	Returns 0 if elements are pushed (if more than 3 nodes exist),
 *	otherwise the elements count in stack a if 3 or less only exist.
 *
 * */

short	init_stacks(t_list **stack_a , t_list **stack_b){
	size_t stack_size = ft_lstsize(*stack_a);
	if(stack_size > 3)
	{
		stack_size -= 3;
		while(stack_size--)
			push(stack_b, stack_a, "b");
		return 0;
	}
	else
		return stack_size;
}
