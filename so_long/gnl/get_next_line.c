/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:16:00 by siokim            #+#    #+#             */
/*   Updated: 2022/02/08 15:52:45 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_line(char *tmp_str)
{
	char		*line;
	size_t		i;

	line = (char *)malloc(sizeof(char) * (ft_strlen(tmp_str) + 1));
	if (!line)
		return (0);
	i = 0;
	while (tmp_str[i])
	{
		line[i] = tmp_str[i];
		if (tmp_str[i++] == '\n')
			break ;
	}
	line[i] = 0;
	return (line);
}

char	*free_str(char *str)
{
	if (str)
		free(str);
	return (0);
}

char	*new_tmp_str(char *buffer, char *tmp_str)
{
	if (*buffer && *(ft_strchr(buffer, '\n') + 1))
	{
		tmp_str = free_str(tmp_str);
		tmp_str = ft_strjoin(tmp_str, ft_strchr(buffer, '\n') + 1);
	}
	else if (tmp_str)
		tmp_str = free_str(tmp_str);
	buffer = free_str(buffer);
	return (tmp_str);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*tmp_str;
	char		*line;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE < 1 || !buffer)
		return (buffer = free_str(buffer));
	ft_bzero(buffer, BUFFER_SIZE + 1);
	if (!tmp_str || !ft_strchr(tmp_str, '\n'))
	{
		if (read(fd, buffer, BUFFER_SIZE) < 1 && !tmp_str)
			return (buffer = free_str(buffer));
		while (*buffer)
		{
			tmp_str = ft_strjoin(tmp_str, buffer);
			if (ft_strchr(tmp_str, '\n'))
				break ;
			buffer[read(fd, buffer, BUFFER_SIZE)] = 0;
		}
	}
	else
		buffer = ft_strjoin(buffer, tmp_str);
	line = new_line(tmp_str);
	tmp_str = new_tmp_str(buffer, tmp_str);
	return (line);
}
