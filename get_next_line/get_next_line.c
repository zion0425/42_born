/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:16:00 by siokim            #+#    #+#             */
/*   Updated: 2022/01/22 20:24:34 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>
char	*get_next_line(int fd)
{
	static char *str;
	char	*line;
	size_t	last_str_idx;
	size_t	last_line_idx;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (0);
	last_str_idx = read(fd, str, BUFFER_SIZE);
	last_line_idx = ft_strchr_idx(str,10);
	if (last_line_idx)
	{
		line = (char *)malloc(sizeof(char) * (last_line_idx + 1));
		if (!line)
			return (0);
		ft_strlcpy(line, str, last_line_idx);
		return (line);
	}
	str[last_str_idx] = 0;
	return (str);
}


//int main()
//{
//	int fd;

//	fd = open("./test.txt", O_RDONLY);
//	printf("%s\n", get_next_line(fd));
//}
