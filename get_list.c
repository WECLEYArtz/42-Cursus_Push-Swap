/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmounsi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:05:19 by ahmounsi          #+#    #+#             */
/*   Updated: 2026/01/15 23:48:30 by ahmounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static short	node_dup(t_list *stack_a, int value)
{
	while (stack_a)
	{
		if (*(int *)stack_a->content == value)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

/*
 * allocate for an integer to be the new node's content
 * */
static t_list	*int_to_node(char **argv, short *valid)
{
	int	*integer;

	integer = malloc(sizeof(int));
	if (!integer)
		return (NULL);
	*integer = ft_atoi_custom(argv, valid);
	return (ft_lstnew(integer));
}

static void	clean_kill(t_list **stack_a)
{
	ft_lstclear(stack_a, free);
	exit(-1);
}

static void	parse_argument(t_list **stack_a, char **argv, short *valid)
{
	t_list	*new;

	while (**argv)
	{
		if (**argv == ' ')
		{
			(*argv)++;
			continue ;
		}
		if (**argv == '\0')
			return ;
		*valid = 0;
		if (!(ft_isdigit(**argv) || **argv == '-' || **argv == '+'))
			return ;
		new = int_to_node(argv, valid);
		if (!new)
			clean_kill(stack_a);
		if (*valid == 0 || node_dup(*stack_a, *(int *)(new)->content))
		{
			*valid = 0;
			return ;
		}
		ft_lstadd_back(stack_a, new);
	}
}

t_list	*get_list(char **argv)
{
	t_list	*stack_a;
	short	valid;

	valid = 1;
	stack_a = NULL;
	while (valid && *argv)
	{
		valid = 0;
		if (**argv == '\0')
			break ;
		parse_argument(&stack_a, argv, &valid);
		argv++;
	}
	if (!valid)
	{
		ft_lstclear(&stack_a, free);
		write(2, "Error\n", 6);
		exit(-1);
	}
	return (stack_a);
}
