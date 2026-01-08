#include "libft/libft.h"
#include "push_swap.h"

// 49448 43638 5664 46265 39002\ 31767\ 48734\ 10533 2019 35284

static void	init_stacks(t_stacks stacks);
static void	hard_sort(t_list **st_a);

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
	init_stacks(stacks);
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
static void	init_stacks(t_stacks stacks)
{
	size_t	stack_size;

	stack_size = ft_lstsize(*(stacks.a));
	if (stack_size > 3)
	{
		stack_size -= 3;
		while (stack_size--)
			p(stacks.b, stacks.a, "b");
	}
	hard_sort(stacks.a);
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
