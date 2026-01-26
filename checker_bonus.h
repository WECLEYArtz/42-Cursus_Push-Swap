/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmounsi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:31:30 by ahmounsi          #+#    #+#             */
/*   Updated: 2026/01/26 11:31:31 by ahmounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Bonus helpers
short	is_instr(char *buff);
void	apply_checker_instr(t_list *instr_list, t_stacks stacks);
void	clean_up(t_stacks stacks, t_list **instr_list, char *buff);
