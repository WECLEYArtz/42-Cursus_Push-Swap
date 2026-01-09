#include "libft/libft.h"
#include "push_swap.h"

static t_stacks	init_stacks(t_list **stack_a, t_list **stack_b, char **argv);
static void	hard_sort(t_list **st_a);

int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_stacks	stacks;

	if (argc < 2)
		return (1);
	stacks = init_stacks(&stack_a, &stack_b, argv);

	// if(is_sorted())
	// 		return; >>>  check wether its sorted or not befor doing anything
	//
	// check_circular(); >>> needed to avoid pushing for easy to sort case

	if (stack_b)
		turk_sort(stacks);
	ft_lstclear(stacks.a, free);
	ft_lstclear(stacks.b, free);
}


/*	Takes stack a and b to to push everything from a to b.
 *	Leaves 3 nodes in stack a.
 *	Returns 0 if elements are pushed (if more than 3 nodes exist),
 *	otherwise the elements count in stack a if 3 or less only exist.
 *
 * */
static t_stacks	init_stacks(t_list **stack_a, t_list **stack_b, char **argv)
{
	t_stacks	stacks;
	size_t		stack_size;

	*stack_a = get_list(argv+1);
	*stack_b = NULL;
	stacks.a = stack_a;
	stacks.b = stack_b;

	stack_size = ft_lstsize(*(stacks.a));
	if (stack_size > 3)
	{
		stack_size -= 3;
		while (stack_size--)
			p(stacks.b, stacks.a, "b");
	}
	hard_sort(stacks.a);
	return (stacks);
}


static void	hard_sort(t_list **st_a)
{
	if(!(*st_a)->next)
			return;
	if (*(int *)((*st_a)->content) > *(int *)((*st_a)->next->content))
		s(st_a, "a");

	if (((*st_a)->next->next) &&
			(*(int *)((*st_a)->next->content)
			 > *(int *)((*st_a)->next->next->content)))
	{
		r(st_a, "a");
		s(st_a, "a");
		rr(st_a, "a");
		if (*(int *)((*st_a)->content) > *(int *)((*st_a)->next->content))
			s(st_a, "a");
	}
}

