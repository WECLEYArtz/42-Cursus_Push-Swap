#include <stdio.h>
#include "push_swap.debuggers.h"

// simply a function that prints the digits in stacks
void list_stacks(t_list *stack_a ,t_list *stack_b)
{
	write(1, "\033cstack a >>>\n", 14);
	while(stack_a)
	{
		printf("- %d\n",*(int *)(stack_a->content));
		stack_a = stack_a->next;
	}

	write(1, "stack b >>>\n", 13);
	while(stack_b)
	{
		printf("- %d\n",*(int *)(stack_b->content));
		stack_b = stack_b->next;
	}

	getchar();
}



// [Fun Experment]
// while(1)
// {
// 	while(stack_a)
// 	{
// 		write(1, "\033cstack a >>>\n", 14);
// 		list_list(stack_a); // just show what we got.
// 		write(1, "stack b >>>\n", 12);
// 		list_list(stack_b); // just show what we got.
// 		getchar();
// 		push(&stack_b, &stack_a, "pb\n");
// 	}
// 	while(stack_b)
// 	{
// 		write(1, "\033cstack b >>>\n", 14);
// 		list_list(stack_b); // just show what we got.
// 		write(1, "stack a >>>\n", 12);
// 		list_list(stack_a); // just show what we got.
// 		getchar();
// 		push(&stack_a, &stack_b, "pa\n");
// 	}
// }
