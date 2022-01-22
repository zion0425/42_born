/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:59:39 by siokim            #+#    #+#             */
/*   Updated: 2022/01/22 20:09:51 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	const char mem_c = (char)c;

	while (*s || !mem_c)
		if (*s++ == mem_c)
			return ((char *)--s);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	j;
	unsigned int	i;
	char			*tmp_str;

	j = start;
	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	tmp_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp_str)
		return (0);
	while (i < len && s[j] && start < ft_strlen(s))
		tmp_str[i++] = s[j++];
	tmp_str[i] = 0;
	return (tmp_str);
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

size_t	ft_strchr_idx(const char *s, int c)
{
	const char mem_c = (char)c;
	size_t	i;

	i = 0;
	while (*s || !mem_c)
	{
		if (*s++ == mem_c)
			return (i);
		i++;
	}
	return (0);
}
