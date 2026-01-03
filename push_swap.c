// ====[ DEBUGGERS ]====
#include "push_swap.debuggers.h"
// =====================
#include "push_swap.h"
#include "libft/libft.h"
#include <unistd.h>

int main(int argc, char **argv)
{
	if(argc < 2)
		return (1);
	t_list *stack_a = get_list(argv+1);
	t_list *stack_b = NULL;
	short init_return;

	init_return = init_stacks(&stack_a ,&stack_b);
	if (init_return == 0)
	{
		turk_sort(stack_a, stack_b);
	}
	// list_stacks(stack_a, stack_b);
	ft_lstclear(&stack_a, free);
}
