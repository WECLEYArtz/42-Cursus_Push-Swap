/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_custom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmounsi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:30:19 by ahmounsi          #+#    #+#             */
/*   Updated: 2026/01/15 23:48:30 by ahmounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static long	ft_atoi_convert(char **argv, short *success)
{
	long	result;

	result = 0;
	while (ft_isdigit(**argv))
	{
		if ((int)((result * 10) + (int)(**argv - '0')) < result)
		{
			if (ft_strncmp(*argv - 10, "-2147483648", 11) == 0)
				result = (result * 10) + (*(*argv)++ - '0');
			else
				return (0);
		}
		else
			result = (result * 10) + (*(*argv)++ - '0');
	}
	if (**argv == ' ' || **argv == '\0')
		*success = 1;
	return (result);
}

int	ft_atoi_custom(char **argv, short *success)
{
	short	sign;

	sign = 1;
	if (**argv == '+' || (**argv == '-'))
	{
		if (**argv == '-')
			(sign = -1);
		(*argv)++;
	}
	if (ft_isdigit(**argv))
		return ((long)ft_atoi_convert(argv, success) * sign);
	else
		return (0);
}
