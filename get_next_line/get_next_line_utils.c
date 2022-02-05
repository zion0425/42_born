/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:59:39 by siokim            #+#    #+#             */
/*   Updated: 2022/02/05 21:35:49 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
size_t	ft_strlen(const char *s)
{
	size_t	i;
	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_strjoin_line(char *s1, char *s2)
{
	char	*tmp_str;
	int	i;

	i = -1;
	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (s1 && !s2)
		return (ft_strdup(s1));
	else if (!s1 && !s2)
		return (0);
	if ((tmp_str = (char *)malloc(sizeof(char) * \
		(ft_strlen(s1) + ft_strlen(s2) + 1))) == 0)
		return (0);
	while (s1[++i])
		tmp_str[i] = s1[i];
	while (*s2)
	{
		tmp_str[i++] = *s2;
		if (*s2++ == '\n')
			break;
	}
	if (!s1)
		free(s1);
	tmp_str[i] = 0;
	return (tmp_str);
}

void	*ft_memset(void *b, int c, size_t len)
{
	const unsigned char	mem_c = (unsigned char)c;
	unsigned char	*mem_b;

	mem_b = (unsigned char *)b;
	while (len--)
		*(mem_b + len) = mem_c;
	return (mem_b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	size_t	i;

	i = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	str[i] = 0;
	while (i--)
		str[i] = s1[i];
	if (!s1)
		free(s1);
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tmp_str;
	int	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (s1 && !s2)
		return (ft_strdup(s1));
	else if (!s1 && !s2)
		return (0);
	if ((tmp_str = (char *)malloc(sizeof(char) * \
		(ft_strlen(s1) + ft_strlen(s2) + 1))) == 0)
		return (0);
	while (s1[++i])
		tmp_str[i] = s1[i];
	while (s2[j])
		tmp_str[i++] = s2[j++];
	
	// 이게 제대로 작동 안 함
	if (*s1)
		free(s1);
	tmp_str[i] = 0;
	return (tmp_str);
}

char	*ft_strchr(const char *s, int c)
{
	const char mem_c = (char)c;

	if (!s)
		return (0);
	while (*s || !mem_c)
		if (*s++ == mem_c)
			return ((char *)--s);
	return (0);
}
