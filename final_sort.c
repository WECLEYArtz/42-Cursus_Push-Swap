#include "libft/libft.h"
#include "push_swap.h"

void final_sort(t_list **stack_a, size_t stack_len_a)
{

	t_list *work_node;
	t_cmp_vars cmp;

	work_node = *stack_a;
	cmp = init_cmp_vars(*((int *)work_node->content), INT_MAX);

	while (work_node)
		update_for_min(&work_node, &cmp);
	if (cmp.result > stack_len_a / 2)
	{
		cmp.result = stack_len_a - cmp.result;
		while(cmp.result--)
			rr(stack_a, "a");
	}
	else
		while(cmp.result--)
			r(stack_a, "a");
}
