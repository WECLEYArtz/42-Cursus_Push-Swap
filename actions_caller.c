#include "push_swap.h"

const short	silent = 0;

void	p(t_list **stack_dst_p, t_list **stack_src_p, char *stack_name)
{
	push(stack_dst_p, stack_src_p);
	if (!silent)
	{
		write(1, "p", 1);
		write(1, stack_name, 1);
		write(1, "\n", 1);
	}
}

void	r(t_list **stack_p, char *stack_name)
{
	rotate(stack_p);
	if (!silent)
	{
		write(1, "r", 1);
		write(1, stack_name, 1);
		write(1, "\n", 1);
	}
}

void	rr(t_list **stack_p, char *stack_name)
{
	revrotate(stack_p);
	if (!silent)
	{
		write(1, "rr", 2);
		write(1, stack_name, 1);
		write(1, "\n", 1);
	}
}

void	s(t_list **stack_p, char *stack_name)
{
	swap(stack_p);
	if (!silent)
	{
		write(1, "s", 1);
		write(1, stack_name, 1);
		write(1, "\n", 1);
	}
}

void	rr__(t_stacks stacks)
{
	rotate(stacks.a);
	rotate(stacks.b);
	if (!silent)
		write(1, "rr\n", 3);
}

void	rrr_(t_stacks stacks)
{
	revrotate(stacks.a);
	revrotate(stacks.b);
	if (!silent)
		write(1, "rrr\n", 4);
}
