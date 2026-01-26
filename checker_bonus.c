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

#include "checker_bonus.h"

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
			clean_up(stacks, &instr_list, buff);
			get_next_line(-1);
			write(2, "Error\n", 6);
			exit(-1);
		}
		tmp = ft_lstnew(buff);
		if (!tmp)
			return (clean_up(stacks, &instr_list, buff), NULL);
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
		apply_checker_instr(tmp, stacks);
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
