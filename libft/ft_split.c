/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:20:00 by siokim            #+#    #+#             */
/*   Updated: 2022/01/01 17:04:02 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	arr2_cnt(const char *s, char c)
{
	size_t	cnt;

	if (!s || !ft_strlen(ft_strtrim(s, &c)))
		return (0);
	cnt = 1;
	while (ft_strchr(s, c))
	{
		s = ft_strchr(s, c) + 1;
		if (s)
			if (!ft_strncmp(s, &c, 1))
				cnt--;
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
	if ((s))
		while (!ft_strncmp(s + 1, &c, 1))
			s++;
	if (!s)
		return (s_size);
	return (s_size - ft_strlen(s));
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	arr2_size;
	size_t	arr1_size;
	size_t	i;

	if (!s || !c)
		return (0);
	s = ft_strtrim(s, &c);
	arr2_size = arr2_cnt(s, c);
	arr1_size = 0;
	i = -1;
	str = (char **)malloc(sizeof(char *) * (arr2_size + 1));
	if (!str)
		return (0);
	while (++i < arr2_size)
	{
		arr1_size = arr1_cnt(s, c);
		str[i] = (char *)malloc(sizeof(char) * (arr1_size + 1));
		ft_strlcpy(str[i], s, arr1_size + 1);
		str[i] = ft_strtrim(str[i], &c);
		s += arr1_size + 1;
	}
	str[arr2_size] = 0;
	return (str);
}
