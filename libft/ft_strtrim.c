/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 12:22:50 by siokim            #+#    #+#             */
/*   Updated: 2022/01/10 15:04:53 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
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
	str = malloc(sizeof(char) * (s1_size + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, s1_size + 1);
	return (str);
}
