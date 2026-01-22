/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmounsi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 00:30:44 by ahmounsi          #+#    #+#             */
/*   Updated: 2026/01/22 00:30:44 by ahmounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "push_swap.h"

short	is_instr(char *buff)
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

void	apply_checker_instr(t_list *instr_list, t_stacks stacks)
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

void	clean_up(t_stacks stacks, t_list **instr_list)
{
	ft_lstclear(stacks.a, free);
	ft_lstclear(stacks.b, free);
	ft_lstclear(instr_list, free);
}

void	flush_gnl()
{
	char *buff;

	while (1)
	{
		buff = get_next_line(0);
		if(!buff)
			return;
		free(buff);
	}
}
