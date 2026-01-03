#include "push_swap.h"

static	t_cmp_vars	*alloc_cmp_vars (int min, int target)
{
	t_cmp_vars *cmps;

	cmps =  malloc(sizeof(t_cmp_vars));
	cmps->min = min;
	cmps->target = target;
	return cmps;
}


static	t_mv_vars	*alloc_mvs_vars(void)
{
	t_mv_vars *mvs;

	mvs =  malloc(sizeof(t_mv_vars));
	mvs->moves_count = 0;
	mvs->moves_ret = 0;
	return mvs;
}


static	void update_min(int value, t_cmp_vars *cmps, t_mv_vars *mvs)
{
	if(value < cmps->min)
	{
		cmps->min = value;
		mvs->moves_ret = mvs->moves_count++;
	}
}


static	void update_min_target(int value, t_cmp_vars *cmps, t_mv_vars *mvs)
{
	if(value < cmps->min && value > cmps->target)
	{
		cmps->min = value;
		mvs->moves_ret = mvs->moves_count++;
	}
}


size_t get_moves_to_target(t_list *stack, int target)
{
	if(!stack || !(stack->content))
		return 0;
	t_mv_vars *mvs;
	t_cmp_vars *cmps;

	cmps = alloc_cmp_vars(*(int *)(stack->content), target);
	mvs = alloc_mvs_vars();
	while(stack)
	{
		update_min(*(int *)(stack->content), cmps, mvs);
		stack = stack->next;
		if(cmps->min > target)
			break;
	}
	while(stack)
	{
		update_min_target(*(int *)(stack->content), cmps, mvs);
		stack = stack->next;
	}
	return mvs->moves_ret;
}
