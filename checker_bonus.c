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

void	append_instr(t_list **instr_list, char *buff)
{
	if (ft_strncmp(buff, "sa\n", 3) == 0)
		return (ft_lstadd_back(instr_list, ft_lstnew(ft_strdup("sa"))));
	if (ft_strncmp(buff, "sb\n", 3) == 0)
		return (ft_lstadd_back(instr_list, ft_lstnew(ft_strdup("sb"))));
	if (ft_strncmp(buff, "ss\n", 3) == 0)
		return (ft_lstadd_back(instr_list, ft_lstnew(ft_strdup("ss"))));
	if (ft_strncmp(buff, "pa\n", 3) == 0)
		return (ft_lstadd_back(instr_list, ft_lstnew(ft_strdup("pa"))));
	if (ft_strncmp(buff, "pb\n", 3) == 0)
		return (ft_lstadd_back(instr_list, ft_lstnew(ft_strdup("pb"))));
	if (ft_strncmp(buff, "ra\n", 3) == 0)
		return (ft_lstadd_back(instr_list, ft_lstnew(ft_strdup("ra"))));
	if (ft_strncmp(buff, "rb\n", 3) == 0)
		return (ft_lstadd_back(instr_list, ft_lstnew(ft_strdup("rb"))));
	if (ft_strncmp(buff, "rr\n", 3) == 0)
		return (ft_lstadd_back(instr_list, ft_lstnew(ft_strdup("rr"))));
	if (ft_strncmp(buff, "rra\n", 4) == 0)
		return (ft_lstadd_back(instr_list, ft_lstnew(ft_strdup("rra"))));
	if (ft_strncmp(buff, "rrb\n", 4) == 0)
		return (ft_lstadd_back(instr_list, ft_lstnew(ft_strdup("rrb"))));
	if (ft_strncmp(buff, "rrr\n", 4) == 0)
		return (ft_lstadd_back(instr_list, ft_lstnew(ft_strdup("rrr"))));
	ft_lstclear(instr_list, free);
	write(2, "Error\n", 6);
	exit(1);
}

void	apply_instr(t_list *instr_list, t_stacks stacks)
{
	if (ft_strncmp(instr_list->content, "sa\n", 3) == 0)
		return (s(stacks.a, "a"));
	if (ft_strncmp(instr_list->content, "sb\n", 3) == 0)
		return (s(stacks.b, "b"));
	if (ft_strncmp(instr_list->content, "ss\n", 3) == 0)
		return (ss_(stacks));
	if (ft_strncmp(instr_list->content, "pa\n", 3) == 0)
		return (p(stacks.a, stacks.b, "a"));
	if (ft_strncmp(instr_list->content, "pb\n", 3) == 0)
		return (p(stacks.b, stacks.a, "b"));
	if (ft_strncmp(instr_list->content, "ra\n", 3) == 0)
		return (r(stacks.a, "a"));
	if (ft_strncmp(instr_list->content, "rb\n", 3) == 0)
		return (r(stacks.b, "b"));
	if (ft_strncmp(instr_list->content, "rr\n", 3) == 0)
		return (rr__(stacks));
	if (ft_strncmp(instr_list->content, "rra\n", 4) == 0)
		return (rr(stacks.a, "a"));
	if (ft_strncmp(instr_list->content, "rrb\n", 4) == 0)
		return (rr(stacks.b, "b"));
	if (ft_strncmp(instr_list->content, "rrr\n", 4) == 0)
		return (rrr_(stacks));
}

void	get_inputs(t_list **instr_list)
{
	char	*buff;

	while (1)
	{
		buff = get_next_line(0);
		if (!buff)
			break ;
		append_instr(instr_list, buff);
		free(buff);
	}
}

void	apply_inputs(t_stacks stacks, t_list **instr_list)
{
	t_list	*tmp;

	if (!instr_list || !*instr_list)
		return ;
	while (instr_list)
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
	stacks.a = &stack_a;
	stacks.b = &stack_b;
	instr_list = NULL;
	get_inputs(&instr_list);
	apply_inputs(stacks, &instr_list);
	if (examin_status(&stack_a))
		write(2, "OK\n", 3);
	else 
		write(2, "KO\n", 3);
}
