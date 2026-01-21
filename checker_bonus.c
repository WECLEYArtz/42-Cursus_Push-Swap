/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmounsi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 23:05:19 by ahmounsi          #+#    #+#             */
/*   Updated: 2026/01/15 23:48:30 by ahmounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void	clean_up(t_stacks stacks, t_list **instr_list)
{
	ft_lstclear(stacks.a, free);
	ft_lstclear(stacks.b, free);
	ft_lstclear(instr_list, free);
}

static short	is_instr(char *buff)
{
	if (ft_strncmp(buff, "sa\n", 3) == 0)
		return (1);
	if (ft_strncmp(buff, "sb\n", 3) == 0)
		return (1);
	if (ft_strncmp(buff, "ss\n", 3) == 0)
		return (1);
	if (ft_strncmp(buff, "pa\n", 3) == 0)
		return (1);
	if (ft_strncmp(buff, "pb\n", 3) == 0)
		return (1);
	if (ft_strncmp(buff, "ra\n", 3) == 0)
		return (1);
	if (ft_strncmp(buff, "rb\n", 3) == 0)
		return (1);
	if (ft_strncmp(buff, "rr\n", 3) == 0)
		return (1);
	if (ft_strncmp(buff, "rra\n", 4) == 0)
		return (1);
	if (ft_strncmp(buff, "rrb\n", 4) == 0)
		return (1);
	if (ft_strncmp(buff, "rrr\n", 4) == 0)
		return (1);
	return (0);
}

static void	apply_instr(t_list *instr_list, t_stacks stacks)
{
	if (ft_strncmp(instr_list->content, "sa\n", 3) == 0)
		return (s(stacks.a, "a", 0));
	if (ft_strncmp(instr_list->content, "sb\n", 3) == 0)
		return (s(stacks.b, "b", 0));
	if (ft_strncmp(instr_list->content, "ss\n", 3) == 0)
		return (ss_(stacks, 0));
	if (ft_strncmp(instr_list->content, "pa\n", 3) == 0)
		return (p(stacks.a, stacks.b, "a", 0));
	if (ft_strncmp(instr_list->content, "pb\n", 3) == 0)
		return (p(stacks.b, stacks.a, "b", 0));
	if (ft_strncmp(instr_list->content, "ra\n", 3) == 0)
		return (r(stacks.a, "a", 0));
	if (ft_strncmp(instr_list->content, "rb\n", 3) == 0)
		return (r(stacks.b, "b", 0));
	if (ft_strncmp(instr_list->content, "rr\n", 3) == 0)
		return (rr__(stacks, 0));
	if (ft_strncmp(instr_list->content, "rra\n", 4) == 0)
		return (rr(stacks.a, "a", 0));
	if (ft_strncmp(instr_list->content, "rrb\n", 4) == 0)
		return (rr(stacks.b, "b", 0));
	if (ft_strncmp(instr_list->content, "rrr\n", 4) == 0)
		return (rrr_(stacks, 0));
}

static t_list	*get_inputs(t_stacks stacks)
{
	t_list	*instr_list;
	t_list	*tmp;
	char	*buff;

	instr_list = NULL;
	while (1)
	{
		buff = get_next_line(0);
		if (!buff)
			break ;
		if (!is_instr(buff))
		{
			clean_up(stacks, &instr_list);
			write(2, "Error\n", 6);
			exit(-1);
		}
		tmp = ft_lstnew(buff);
		if (!tmp)
			return (clean_up(stacks, &instr_list), NULL);
		ft_lstadd_back(&instr_list, tmp);
	}
	return (instr_list);
}

static void	apply_inputs(t_stacks stacks, t_list **instr_list)
{
	t_list	*tmp;

	if (!*instr_list)
		return ;
	while (*instr_list)
	{
		tmp = *instr_list;
		apply_instr(tmp, stacks);
		*instr_list = tmp->next;
		ft_lstdelone(tmp, free);
	}
}

int	main(int argc, char **argv)
{
	t_list		*stack_a;
	t_list		*stack_b;
	t_stacks	stacks;
	t_list		*instr_list;

	if (argc < 2)
		return (0);
	stack_a = get_list(++argv);
	stack_b = NULL;
	if (!stack_a)
		return (-1);
	stacks.a = &stack_a;
	stacks.b = &stack_b;
	instr_list = get_inputs(stacks);
	if (instr_list)
		apply_inputs(stacks, &instr_list);
	if (examin_status(&stack_a))
		write(2, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
}
