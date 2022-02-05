/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:16:00 by siokim            #+#    #+#             */
/*   Updated: 2022/02/05 20:23:46 by siokim           ###   ########.fr       */
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
	int		last_line_idx;
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
		if ((last_line_idx = read(fd, buffer, BUFFER_SIZE)) < 1)
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
	
	// tmp_str 프리
	// free(tmp_str);

	line = ft_strjoin(line, tmp_str);
	
	// tmp_str에서 \n까지 line에 복사
	// if ((line = (char *)malloc(sizeof(char) * (ft_strlen(tmp_str) + 1))) == 0)
	// 	return (0);
	// size_t	i = 0;
	// while (tmp_str && tmp_str[i] != '\n')
	// {
	// 	line[i] = tmp_str[i];
	// 	i++;
	// }
	// if (tmp_str)
	// {
	// 	line[i++] = '\n';
	// 	line[i] = 0;
	// }
	

	// 여기서 tmp_str의 앞에 쓰레기 값들이 생겨나게 됨. 즉 이전 값을들 메모리 할당 해제 해주고 새로 주소값 줘야 함.
	// tmp_str이 아니라 buffer로 비교하면 됨..;
	if (ft_strchr(tmp_str, '\n') != 0)
	{
		if(ft_strchr(tmp_str, '\n') + 1 == 0)
			free(tmp_str);
		else
			tmp_str = ft_strchr(tmp_str, '\n') + 1;
	}

	free(buffer);
	return (line);
}

// int main()
// {
// 	int fd;
// 	char *str;
	
// 	// fd = open("./gnlTester/files/empty", O_RDONLY);
// 	fd = open("./test.txt", O_RDONLY);

// 	for (int i = 0; i <3; i++){
// 		printf("result : %s", str = get_next_line(fd));
// 		free(str);
// 	}	
// }