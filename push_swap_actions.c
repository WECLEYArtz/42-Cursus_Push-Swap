#include "push_swap.h"

void push(t_list **stack_dst_p, t_list **stack_src_p, char *stack_name)
{
	if(!stack_src_p || !*stack_src_p)
		return;
	t_list *tmp = (*stack_src_p)->next;
	ft_lstadd_front(stack_dst_p, *stack_src_p);
	*stack_src_p = tmp;
	// write(1, "p" , 1);
	// write(1, stack_name , 1);
	// write(1, "\n" , 1);
	stack_name=NULL;
}


void rotate(t_list **stack_p, char *stack_name)
{
	if(!stack_p || !(*stack_p) || !(*stack_p)->next)
		return;
	t_list* newback = *stack_p;
	t_list* newhead = (*stack_p)->next;
	ft_lstadd_back(stack_p, *stack_p);
	newback->next = NULL;
	*stack_p = newhead;
	// write(1, "r" , 1);
	// write(1, stack_name , 1);
	// write(1, "\n" , 1);
	stack_name=NULL;
}


void rrotate(t_list **stack_p, char *stack_name)
{
	if(!stack_p || !(*stack_p) || !(*stack_p)->next)
		return;
	t_list *last_node =*stack_p;
	t_list *last_node_depth1=*stack_p;

	while(1)
	{
		last_node = last_node->next;
		if(!(last_node->next))
			break;
		last_node_depth1 = last_node;
	}
	last_node_depth1 -> next = NULL;
	last_node -> next =  *stack_p;
	*stack_p = last_node;

	// write(1, "rr" , 2);
	// write(1, stack_name , 1);
	// write(1, "\n" , 1);
	stack_name=NULL;
}

void swap(t_list **stack_p, char *stack_name)
{
	if(!stack_p || !(*stack_p) || !(*stack_p)->next)
		return;

	t_list *tmp = *stack_p;
	*stack_p = (*stack_p)->next;
	tmp->next = (*stack_p)->next;
	(*stack_p)->next = tmp;

	// write(1, "s" , 1);
	// write(1, stack_name , 1);
	// write(1, "\n" , 1);
	stack_name=NULL;
}
