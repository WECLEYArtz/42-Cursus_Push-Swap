#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

void list_list(t_list *list)
{
	while(list)
	{
		printf("- %d\n",*(int *)(list->content));
		list = list->next;
	}
}

int main(int argc, char **argv)
{
	if(argc < 2)
		return (0);
	t_list *stack_a = get_list(argv+1);
	t_list *stack_b = NULL;

	// list_list(stack_a); // just show what we got.
	// list_list(stack_b); // just show what we got.

	write(1,"\033c",1);
	while(1)
	{
		while(stack_a)
		{
			write(1, "\033cstack a >>>\n", 13);
			list_list(stack_a); // just show what we got.
			write(1, "stack b >>>\n", 12);
			list_list(stack_b); // just show what we got.
			getchar();
			push(&stack_b, &stack_a, "pb\n");
		}
		while(stack_b)
		{
			write(1, "stack b >>>\n", 12);
			list_list(stack_b); // just show what we got.
			write(1, "\033cstack a >>>\n", 13);
			list_list(stack_a); // just show what we got.
			getchar();
			push(&stack_a, &stack_b, "pa\n");
		}
	}
	// rotate(&stack_a,"ra\n");

	ft_lstclear(&stack_a, free);
}


//p *((int *)(headnode->content) )




// ./push 0 1 2 3 4 "111 222 333 444" 99 102 3
//
// iterate on every argv,
//  - if has no space: put its atoi on stack
//  - if has space: split to an array, itterate and add atoi to stack
//
// current ft_lstnew makes a new shit list, content has pointer to variable
