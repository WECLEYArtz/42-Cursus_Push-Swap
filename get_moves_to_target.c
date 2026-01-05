#include "libft/libft.h"
#include "push_swap.h"
#include <stddef.h>

static	t_cmp_vars	init_cmp_vars (int min, int target);
static	t_mv_vars	init_mvs_vars(void);

static	void update_for_min(t_list **stack, t_cmp_vars *cmp, t_mv_vars *mvs);
static	void update_for_target(t_list **stack, t_cmp_vars *cmp, t_mv_vars *mvs);

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
	t_mv_vars mvs;

	cmps = init_cmp_vars(*(int *)(stack_a->content), target);
	mvs = init_mvs_vars();
	while(stack_a)
	{
		update_for_min(&stack_a, &cmps, &mvs);
		if(cmps.min > target)
			break;
	}
	while(stack_a)
		update_for_target(&stack_a, &cmps, &mvs);
	return mvs.final;
}


static	t_cmp_vars	init_cmp_vars (int min, int target)
{
	t_cmp_vars cmp;

	cmp.min = min;
	cmp.target = target;
	return cmp;
}


static	t_mv_vars	init_mvs_vars(void)
{
	t_mv_vars mvs;

	mvs.current = 0;
	mvs.final = 0;
	return mvs;
}


/*
 *	Compare
 * */
static	void update_for_min(t_list **stack, t_cmp_vars *cmp, t_mv_vars *mvs)
{
	int	value = *(int *)((*stack)->content);
	if(value < cmp->min)
	{
		cmp->min = value;
		mvs->final = mvs->current++;
	}
	*stack = (*stack)->next;
}


static	void update_for_target(t_list **stack, t_cmp_vars *cmp, t_mv_vars *mvs)
{
	int	value = *(int *)((*stack)->content);
	if(value < cmp->min && value > cmp->target)
	{
		cmp->min = value;
		mvs->final = mvs->current;
	}
	*stack = (*stack)->next;
}
