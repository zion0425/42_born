/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:16:00 by siokim            #+#    #+#             */
/*   Updated: 2022/02/05 14:29:39 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

// c를 만나는 지점의 인덱스 + 1
//int	ft_strchr_idx(const char *s, int c)
//{
//	const char mem_c = (char)c;
//	size_t	i;

//	i = 1;
//	while (*s || !mem_c)
//	{
//		if (*s++ == mem_c)
//			return (i);
//		i++;
//	}
//	return (0);
//}

char	*get_next_line(int fd)
{
	char	*buffer;
	static char	*tmp_str;
	int	last_line_idx;
	char	*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);

	if ((buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))) == 0)
		return (0);

	line = 0;
	ft_bzero(buffer, BUFFER_SIZE + 1);

	// tmp_str값이 없거나, 값이 있어도 그 값 안에 \n이 없는 경우 read를 반복 실행
	if (!(tmp_str && ft_strchr(tmp_str, '\n')))
	{
		if ((last_line_idx = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(buffer);
			return (0);
		}

		while (last_line_idx && !(ft_strchr((tmp_str = ft_strjoin(tmp_str, buffer)), '\n')))
		{
			last_line_idx = read(fd, buffer, BUFFER_SIZE);
			buffer[last_line_idx] = 0;
		}
	}

	line = ft_strjoin(line, tmp_str);

	if (tmp_str && (tmp_str = ft_strchr(tmp_str, '\n') + 1) == 0)
		free(tmp_str);

	free(buffer);
	return (line);
}

int main()
{
	int fd;
	char *str;

	fd = open("./gnlTester/files/nl", O_RDONLY);

	for (int i = 0 ; i < 2; i++)
	{
		printf("%s", str = get_next_line(fd));
		free(str);
	}
}
