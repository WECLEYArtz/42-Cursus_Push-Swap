#include "./libft/libft.h"
#include <stdlib.h>

static short node_exists(t_list *stack_a, int value)
{

	while(stack_a)
	{
		if( *(int *) stack_a->content == value)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}


static	size_t count_digits(char *str, size_t *i)
{
	size_t digits;

	digits=0;
	if(*str == '-' || *str == '+')
	{
		str++;
		digits++;
	}
	while(*str && ft_isdigit(*str++))
		digits++;
	*i += digits;
	return(digits);

}


/*
 * allocate for an integer to be the new node's content
 * */
static t_list	*int_to_node(char *str, short *valid)
{
	int	*integer;

	integer = malloc(sizeof(int));
	if (!integer)
		return (NULL);
	*integer = ft_atoi_check(str, valid);
	return (ft_lstnew(integer));
}

static	short parse_argument(t_list **new, t_list **stack_a,  char **argv, short* valid)
{
	size_t		i;

	i=0;
	while((*argv)[i])
	{
		if((*argv)[i] == ' ')
		{
			i++;
			continue;
		}
		if(!(*argv)[i])
			return 0;
		if(!ft_isdigit((*argv)[i]))
			if(((*argv)[i] != '-' && (*argv)[i] != '+')  && !ft_isdigit((*argv)[i+1]))
				return(*valid = 0, 0);
		*new = int_to_node( ft_substr(*argv, i, count_digits(&(*argv)[i], &i)),
				valid);
		if(node_exists(*stack_a, *(int *)(*new)->content))
			return(*valid = 0, 0);
		ft_lstadd_back(stack_a, *new);
	}
	return 0;
}

t_list	*get_list(char **argv)
{
	t_list	*stack_a;
	t_list	*new;
	short	valid;

	valid = 1;
	stack_a = NULL;
	while (valid && *argv)
	{
		if(!**argv)
		{
			valid = 0;
			break;
		}
		parse_argument(&new , &stack_a, argv, &valid);
		argv++;
	}
	if(!valid)
	{
		ft_lstclear(&stack_a, free);
		write(1,"Error\n",6);
		exit(1);
	}
	return (stack_a);
}
