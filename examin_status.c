#include "libft/libft.h"
#include "push_swap.h"

void	examin_status(t_list **stack)
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
