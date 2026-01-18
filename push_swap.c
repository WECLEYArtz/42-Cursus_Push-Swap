/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmounsi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:05:19 by ahmounsi          #+#    #+#             */
/*   Updated: 2026/01/18 14:16:32 by ahmounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Takes stack a and b to to push everything from a to b.
 *	Leaves 3 nodes in stack a.
 *	Returns 0 if elements are pushed (if more than 3 nodes exist),
 *	otherwise the elements count in stack a if 3 or less only exist.
 *
 * */
int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_stacks	stacks;

	stack_a = get_list(argv + 1);
	stack_b = NULL;
	if (stack_a)
	{
		stacks.a = &stack_a;
		stacks.b = &stack_b;
		if (argc < 2)
			return (1);
		if(examin_status(stacks.a))
			return(0);
		init_stacks(stacks);
		if (stack_b)
			turk_sort(stacks);
	}
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
}
