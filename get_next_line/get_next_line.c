/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:16:00 by siokim            #+#    #+#             */
/*   Updated: 2022/02/06 16:44:05 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*tmp_str;
	int			last_line_idx;
	char		*line;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line = 0;
	ft_bzero(buffer, BUFFER_SIZE + 1);
	if (!(tmp_str && ft_strchr(tmp_str, '\n')))
	{
		last_line_idx = read(fd, buffer, BUFFER_SIZE);
		if (last_line_idx < 1 && !tmp_str)
		{
			free(buffer);
			buffer = 0;
			return (0);
		}
		while (last_line_idx)
		{
			tmp_str = ft_strjoin(tmp_str, buffer);
			if (ft_strchr(tmp_str, '\n'))
				break ;
			last_line_idx = read(fd, buffer, BUFFER_SIZE);
			buffer[last_line_idx] = 0;
		}
	}
	else
		buffer = ft_strjoin(buffer, tmp_str);
	line = (char *)malloc(sizeof(char) * (ft_strlen(tmp_str) + 1));
	if (!line)
		return (0);
	i = 0;
	while (tmp_str[i])
	{
		if (tmp_str[i] == '\n')
		{
			line[i] = '\n';
			line[i + 1] = 0;
			break ;
		}
		line[i] = tmp_str[i];
		line[i + 1] = 0;
		i++;
	}
	if (*buffer && *(ft_strchr(buffer, '\n') + 1))
	{
		free(tmp_str);
		tmp_str = 0;
		tmp_str = ft_strjoin(tmp_str, ft_strchr(buffer, '\n') + 1);
	}
	else if (tmp_str)
	{
		free(tmp_str);
		tmp_str = 0;
	}
	free(buffer);
	buffer = 0;
	return (line);
}
