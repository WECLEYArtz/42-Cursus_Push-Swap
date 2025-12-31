#include <stdlib.h>
#include "./libft/libft.h"

static void *free_str_arr(char **strs_arr)
{
	unsigned int i = 0;
	if(!strs_arr)
		return NULL;
	while(strs_arr[i])
		free(strs_arr[i++]);
	free(strs_arr);
	return NULL;
}


static void *add_int_node(char *str)
{
	int *integer = malloc(sizeof(int));
	if(!integer)
		return NULL;
	*integer = ft_atoi(str);
	return ft_lstnew(integer);;
}


t_list *get_list(char **argv)
{
	int i;

	t_list *headnode;
	char **tmp;
	headnode = NULL;
	while(*argv)
	{
		if(ft_strchr(*argv, ' '))
		{
			tmp = ft_split(*argv, ' ');
			i = 0;
			while(tmp[i])
				ft_lstadd_back(&headnode, add_int_node(tmp[i++]));
			tmp = free_str_arr(tmp);
		}
		else 
			ft_lstadd_back(&headnode, add_int_node(*argv));
		if (!headnode)
			return NULL;
		argv++;
	}
	return headnode;
}
