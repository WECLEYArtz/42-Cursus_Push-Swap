#include "libft/libft.h"
#include "push_swap.h"

// 49448 43638 5664 46265 39002\ 31767\ 48734\ 10533 2019 35284
int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_stacks	stacks;

	if (argc < 2)
		return (1);
	stack_a = get_list(argv + 1);
	stack_b = NULL;
	stacks.a = &stack_a;
	stacks.b = &stack_b;
	init_stacks(&stack_a, &stack_b);
	if (stack_b)
		turk_sort(stacks);
	ft_lstclear(&stack_a, free);
}


/*	Takes stack a and b to to push everything from a to b.
 *	Leaves 3 nodes in stack a.
 *	Returns 0 if elements are pushed (if more than 3 nodes exist),
 *	otherwise the elements count in stack a if 3 or less only exist.
 *
 * */
void	init_stacks(t_list **stack_a, t_list **stack_b)
{
	size_t	stack_size;

	stack_size = ft_lstsize(*stack_a);
	if (stack_size > 3)
	{
		stack_size -= 3;
		while (stack_size--)
			push(stack_b, stack_a, "b");
	}
	hard_sort(stack_a);
}

void	hard_sort(t_list **st_a)
{
	if(!(*st_a)->next)
			return;
	if (*(int *)((*st_a)->content) > *(int *)((*st_a)->next->content))
		swap(st_a, "a");

	if (((*st_a)->next->next) &&
			(*(int *)((*st_a)->next->content)
			 > *(int *)((*st_a)->next->next->content)))
	{
		rotate(st_a, "a");
		swap(st_a, "a");
		rrotate(st_a, "a");
		if (*(int *)((*st_a)->content) > *(int *)((*st_a)->next->content))
			swap(st_a, "a");
	}
}
