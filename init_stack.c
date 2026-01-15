#include "libft/libft.h"
#include "push_swap.h"

void	init_stacks(t_stacks stacks)
{
	size_t	stack_size;
	int		new_big;
	short	first_two;

	first_two = 2;
	stack_size = ft_lstsize(*(stacks.a));
	if (stack_size > 3)
	{
		new_big = INT_MIN;
		while (stack_size > 3 && first_two--)
		{
			p(stacks.b, stacks.a, "b");
			stack_size--;
			if (*(int *)(*stacks.b)->content > new_big)
				new_big = *(int *)((*stacks.b)->content);
		}
		while (stack_size > 3)
		{
			p(stacks.b, stacks.a, "b");
			stack_size--;
			if (*(int *)(*stacks.b)->content > *(int *)((*stacks.b)->next->content))
				new_big = *(int *)((*stacks.b)->next->content);
			else if(*(int *)(*stacks.b)->content < new_big / 2)
				r(stacks.b, "b");
		}
	}
	hard_sort(stacks.a);
}
