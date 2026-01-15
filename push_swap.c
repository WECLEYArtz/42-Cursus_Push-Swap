#include "libft/libft.h"
#include "push_swap.h"

void		init_stacks(t_stacks stacks);
static void	examin_status(t_list **stack);

int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_stacks	stacks;

	stack_a = get_list(argv + 1);
	stack_b = NULL;
	if (stack_a)
	{
		stacks.a = &stack_a;
		stacks.b = &stack_b;
		if (argc < 2)
			return (1);
		examin_status(stacks.a);
		init_stacks(stacks);
		if (stack_b)
			turk_sort(stacks);
	}
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
}

/*	Takes stack a and b to to push everything from a to b.
 *	Leaves 3 nodes in stack a.
 *	Returns 0 if elements are pushed (if more than 3 nodes exist),
 *	otherwise the elements count in stack a if 3 or less only exist.
 *
 * */
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
			// else if(*(int *)(*stacks.b)->content < *(int *)((*stacks.b)->next->content))
			// 	s(stacks.b, "b");
		}
	}
	hard_sort(stacks.a);
}

static void	examin_status(t_list **stack)
{
	t_list	*work_stack;
	int		prev_val;

	work_stack = *stack;
	if (!work_stack)
		exit(0);
	prev_val = *(int *)(work_stack->content);
	work_stack = work_stack->next;
	while (work_stack)
	{
		if (*(int *)(work_stack->content) < prev_val)
			return ;
		prev_val = *(int *)(work_stack->content);
		work_stack = work_stack->next;
	}
	ft_lstclear(stack, free);
	exit(0);
}
