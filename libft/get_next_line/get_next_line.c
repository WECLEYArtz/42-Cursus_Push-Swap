/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmounsi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:56:51 by ahmounsi          #+#    #+#             */
/*   Updated: 2025/11/13 11:12:00 by ahmounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buff = NULL;

	if (fd < -1 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (fd == -1)
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	if (!buff)
	{
		buff = malloc(BUFFER_SIZE);
		if (!buff)
			return (NULL);
		ft_bzero(buff, BUFFER_SIZE);
	}
	if (buff[0] == '\0' && read(fd, buff, BUFFER_SIZE) <= 0)
		return (ft_clear(NULL, &buff), NULL);
	return (gnl_engine(fd, &buff));
}

char	*gnl_engine(int fd, char **buff)
{
	char	*line;
	size_t	copy_len;
	size_t	line_len;
	ssize_t	read_status;

	line = 0;
	copy_len = 0;
	line_len = 0;
	while (1)
	{
		line = join_ln_cp(line, buff, &line_len, &copy_len);
		if (!line)
			return (ft_clear(NULL, buff), NULL);
		bshift(*buff, copy_len);
		if (line[line_len - 1] == '\n')
			return (line);
		if ((*buff)[0] == '\0')
		{
			read_status = read(fd, *buff, BUFFER_SIZE);
			if (read_status == -1)
				return (ft_clear(line, buff), NULL);
			if (read_status == 0)
				return (ft_clear(NULL, buff), line);
		}
	}
}

char	*join_ln_cp(char *line, char **buff, size_t *line_len, size_t *copy_len)
{
	size_t	i;
	char	*new_line;

	i = 0;
	while (i < BUFFER_SIZE && (*buff)[i])
	{
		i++;
		if ((*buff)[i - 1] == '\n')
			break ;
	}
	new_line = malloc(*line_len + i + 1);
	if (!new_line)
		return (ft_clear(line, buff), NULL);
	if (line)
		ft_memcpy(new_line, line, *line_len);
	ft_memcpy(&new_line[*line_len], *buff, i);
	*copy_len = i;
	*line_len += i;
	new_line[*line_len] = 0;
	return (free(line), new_line);
}
