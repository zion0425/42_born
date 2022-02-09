/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:59:39 by siokim            #+#    #+#             */
/*   Updated: 2022/02/08 14:40:35 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	ft_bzero(void *s, size_t n)
{
	unsigned char		*mem_s;

	mem_s = (unsigned char *)s;
	while (n--)
		*(mem_s + n) = 0;
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
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tmp_str;
	int		i;
	size_t	j;

	i = -1;
	j = 0;
	if (!s1 && s2)
		return (ft_strdup(s2));
	else if (s1 && !s2)
		return (ft_strdup(s1));
	tmp_str = (char *)malloc(sizeof(char) * \
		(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!tmp_str)
		return (0);
	while (s1[++i])
		tmp_str[i] = s1[i];
	while (s2[j])
		tmp_str[i++] = s2[j++];
	s1 = free_str(s1);
	tmp_str[i] = 0;
	return (tmp_str);
}

char	*ft_strchr(const char *s, int c)
{
	const char	mem_c = (char)c;

	if (!s)
		return (0);
	while (*s || !mem_c)
		if (*s++ == mem_c)
			return ((char *)--s);
	return (0);
}
