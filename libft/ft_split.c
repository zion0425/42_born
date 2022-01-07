/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:20:00 by siokim            #+#    #+#             */
/*   Updated: 2022/01/06 20:53:45 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	arr2_cnt(const char *s, char c)
{
	size_t	cnt;

	if (!s || !ft_strlen(s))
		return (0);
	cnt = 1;
	while (ft_strchr(s, c))
	{
		s = ft_strchr(s, c) + 1;
		if (s)
			if (*s == c)
				continue ;
		cnt++;
	}
	return (cnt);
}

size_t	arr1_cnt(const char *s, char c)
{
	size_t	s_size;

	if (!s)
		return (0);
	s_size = ft_strlen(s);
	s = ft_strchr(s, c);
	if (!s)
		return (s_size);
	return (s_size - ft_strlen(s));
}

char	**malloc_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
	return (0);
}

char	*ft_trim(char const *s1, char *set)
{
	char	*str;
	size_t	s1_size;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	s1_size = ft_strlen(s1);
	if (s1_size > 0)
		while (s1[s1_size - 1] && ft_strchr(set, s1[s1_size - 1]))
			s1_size--;
	str = (char *)s1;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	arr2_size;
	size_t	arr1_size;
	size_t	i;

	s = (char const *)ft_trim(s, &c);
	arr2_size = arr2_cnt(s, c);
	i = -1;
	str = (char **)malloc(sizeof(char *) * (arr2_size + 1));
	if (!str)
		return (0);
	while (++i < arr2_size)
	{
		arr1_size = arr1_cnt(s, c);
		str[i] = (char *)malloc(sizeof(char) * (arr1_size + 1));
		if (!str[i])
			return ((char **)malloc_free(str));
		ft_strlcpy(str[i], s, arr1_size + 1);
		s = ft_strchr(s, c);
		while (s && *s == c)
			s++;
	}
	str[arr2_size] = 0;
	return (str);
}
