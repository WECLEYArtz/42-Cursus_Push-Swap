#include "libft/libft.h"
#include "push_swap.h"

static	t_cmp_vars	init_cmp_vars (int min, int target);
static	void update_for_min(t_list **stack, t_cmp_vars *cmp);
static	void update_for_target(t_list **stack, t_cmp_vars *cmp);

/*
 *	Lookup the best position for "target" int "stack",
 *	Return the amount of rotations to get the value,
 *	(returns only for none reversed rotation)
 *
 * */
size_t get_moves_to_target(t_list *stack_a, int target)
{
	if(!stack_a || !(stack_a->content))
		return 0;
	t_cmp_vars cmps;
	size_t result;
	size_t moves;

	moves = 0;
	result = 0;
	cmps = init_cmp_vars(*(int *)(stack_a->content), target);
	while(stack_a)
	{
		update_for_min(&stack_a, &cmps);
		if(cmps.min > target)
			break;
	}
	while(stack_a)
		update_for_target(&stack_a, &cmps);
	return cmps.result;
}


static	t_cmp_vars	init_cmp_vars (int min, int target)
{
	t_cmp_vars cmp;

	cmp.min = min;
	cmp.target = target;
	cmp.iterations = 0;
	cmp.result = 0;
	return cmp;
}


static	void update_for_min(t_list **stack, t_cmp_vars *cmp)
{
	int	value = *(int *)((*stack)->content);
	if(value < cmp->min || value > cmp->target)
	{
		cmp->min = value;
		cmp->result = cmp->iterations;
	}
	cmp->iterations++;
	*stack = (*stack)->next;
}


static	void update_for_target(t_list **stack, t_cmp_vars *cmp)
{
	int	value = *(int *)((*stack)->content);
	if(value < cmp->min && value > cmp->target)
	{
		cmp->min = value;
		cmp->result = cmp->iterations;
	}
	cmp->iterations++;
	*stack = (*stack)->next;
}
