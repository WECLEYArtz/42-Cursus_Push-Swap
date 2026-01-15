#include "./libft/libft.h"
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

static short	parse_argument(t_list **stack_a, char **argv, short *valid)
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
			return (0);
		if (ft_isdigit(**argv) || **argv == '-' || **argv == '+')
			new = int_to_node(argv, valid);
		if (*valid == 0 || node_dup(*stack_a, *(int *)(new)->content))
			return (*valid = 0, 0);
		ft_lstadd_back(stack_a, new);
	}
	return (0);
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
		exit(1);
	}
	return (stack_a);
}
