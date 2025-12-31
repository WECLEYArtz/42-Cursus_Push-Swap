#include "push_swap.h"

void push(t_list **stack_dst_p, t_list **stack_src_p, char *act_name)
{
	if(!stack_src_p || !*stack_src_p)
		return;
	t_list *tmp = (*stack_src_p)->next;
	ft_lstadd_front(stack_dst_p, *stack_src_p);
	*stack_src_p = tmp;
	write(1, "pb\n" , 3);
}


void rotate(t_list **stack_p, char *act_name)
{
	if(!(*stack_p)->next)
		return;
	t_list* newback = *stack_p;
	t_list* newhead = (*stack_p)->next;
	ft_lstadd_back(stack_p, *stack_p);
	newback->next = NULL;
	*stack_p = newhead;
	write(1, act_name , 3);
}


// void rb(t_list **stack_b_p)
// {
// 	if(!(*stack_b_p)->next)
// 		return;
// 	t_list* tmp = (*stack_b_p)->next;
// 	(*stack_b_p)->next = NULL;
// 	ft_lstadd_back(stack_b_p, *stack_b_p);
// 	*stack_b_p = tmp;
// 	write(1, "rb\n" , 3);
// }
//
// 1 -> 2 -> 3 -> 4 -> null
//
// 1 -> 2 -> 3 -> 4 -> null
