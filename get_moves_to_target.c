#include "libft/libft.h"
#include "push_swap.h"
#include <stddef.h>

static	t_cmp_vars	alloc_cmp_vars (int min, int target);
static	t_mv_vars	alloc_mvs_vars(void);
static	void update_for_min(t_list *stack, t_cmp_vars *cmps, t_mv_vars *mvs);
static	void update_for_target(t_list *stack, t_cmp_vars *cmps, t_mv_vars *mvs);

/*
 *	get 
 *
 * */

size_t get_moves_to_target(t_list *stack, int target)
{
	if(!stack || !(stack->content))
		return 0;
	t_cmp_vars cmps;
	t_mv_vars mvs;

	cmps = alloc_cmp_vars(*(int *)(stack->content), target);
	mvs = alloc_mvs_vars();
	while(stack)
	{
		update_for_min(stack, &cmps, &mvs);
		if(cmps.min > target)
			break;
	}
	while(stack)
		update_for_target(stack, &cmps, &mvs);
	return mvs.moves_ret;
}


static	t_cmp_vars	alloc_cmp_vars (int min, int target)
{
	t_cmp_vars cmps;

	cmps.min = min;
	cmps.target = target;
	return cmps;
}


static	t_mv_vars	alloc_mvs_vars(void)
{
	t_mv_vars mvs;

	mvs.moves_count = 0;
	mvs.moves_ret = 0;
	return mvs;
}


static	void update_for_min(t_list *stack, t_cmp_vars *cmps, t_mv_vars *mvs)
{
	size_t value = *(int *)(stack->content);
	if(value < cmps->min)
	{
		cmps->min = value;
		mvs->moves_ret = mvs->moves_count++;
		*stack = *stack->next;
	}
}


static	void update_for_target(t_list *stack, t_cmp_vars *cmps, t_mv_vars *mvs)
{
	size_t value = *(int *)(stack->content);
	if(value < cmps->min && value > cmps->target)
	{
		cmps->min = value;
		mvs->moves_ret = mvs->moves_count;
		*stack = *stack->next;
	}
}

