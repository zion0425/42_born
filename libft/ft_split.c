/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:20:00 by siokim            #+#    #+#             */
/*   Updated: 2022/01/04 18:25:01 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s || !c)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	s1_size;

	// printf("\nbefore : %s-", s1);
	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	s1_size = ft_strlen(s1);
	if (s1_size > 0)
		while (s1[s1_size - 1] && ft_strchr(set, s1[s1_size - 1]))
			s1_size--;
	str = malloc(sizeof(char) * (s1_size + 1));
	if (!str)
		return (0);
	// printf("\nafter : %s", s1);
	ft_strlcpy(str, s1, s1_size + 1);
	// printf("\nafterstr2 : %s", str);
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize < 1)
		return (src_len);
	while (*src && --dstsize > 0)
		*dst++ = *src++;
	*dst = 0;
	return (src_len);
}

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
				continue;
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
	if (!s){
		return (s_size);
	}
	return (s_size - ft_strlen(s));
}

char	**malloc_free(char **s)
{
	int	i;

	i = 0;
	while(s[i])
		free(s[i++]);
	free(s);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	arr2_size;
	size_t	arr1_size;
	size_t	i;

	if (!s)
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
		if (!str)
			return ((char **)malloc_free(str));
		ft_strlcpy(str[i], s, arr1_size + 1);
		s = ft_strchr(s,c);
		while (*s == c)
		s = ft_strtrim(s, &c);
	}
	str[arr2_size] = 0;
	return (str);
}

int main()
{
	char *a = "   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ";
	char **b;
	b = ft_split(a,' ');
	int i = 0;
	while(b[i])
	{
		printf("i : %d  s : %s\n", i, b[i]);
		i++;
	}
}
