/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmounsi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:33:52 by ahmounsi          #+#    #+#             */
/*   Updated: 2025/11/13 11:12:00 by ahmounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	bshift(char *dst, size_t shift_gap)
{
	char	*src;
	size_t	shift_count;

	shift_count = BUFFER_SIZE - shift_gap;
	src = &dst[shift_gap];
	if (shift_gap && shift_gap < BUFFER_SIZE && dst != src)
	{
		while (shift_count-- && *dst)
			*dst++ = *src++;
	}
	ft_bzero(dst, shift_gap);
}

void	ft_clear(char *line, char **buffer)
{
	free(line);
	free(*buffer);
	*buffer = NULL;
}
