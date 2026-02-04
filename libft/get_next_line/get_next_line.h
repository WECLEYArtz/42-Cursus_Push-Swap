/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmounsi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:04:47 by ahmounsi          #+#    #+#             */
/*   Updated: 2025/11/13 11:11:59 by ahmounsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 69
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

char	*get_next_line(int fd);
char	*gnl_engine(int fd, char **buff);
char	*join_ln_cp(char *line, char **buff, size_t *line_len,
			size_t *copy_len);
void	bshift(char *dst, size_t shift_gap);
void	ft_clear(char *line, char **buffer);
void	ft_bzero(void *dest, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t len);

#endif
