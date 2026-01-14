/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmounsi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:30:19 by ahmounsi          #+#    #+#             */
/*   Updated: 2025/10/29 00:59:47 by ahmounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || (9 <= c && c <= 13))
		return (1);
	return (0);
}

static long	ft_atoi_convert(const char *str, short sign, short *success)
{
	long	result;

	result = 0;
	while (*str && ft_isdigit(*str))
	{
		if ((int)((result * 10) + (int)(*str - '0')) < result)
		{
			if (sign == -1 && ft_strncmp(str - 9, "2147483648", 10) == 0)
				result = (result * 10) + (*str++ - '0');
			else
			{
				if (success)
					*success = 0;
				return (0);
			}
		}
		else
			result = (result * 10) + (*str++ - '0');
	}
	return (result);
}

int	ft_atoi_check(const char *str, short *overflowed)
{
	long	result;
	short	sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || (*str == '-'))
	{
		if (*str == '-')
			(sign = -1);
		str++;
	}
	result = ft_atoi_convert(str, sign, overflowed);
	return (result * sign);
}
