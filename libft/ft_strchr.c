/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:13:47 by siokim            #+#    #+#             */
/*   Updated: 2022/01/10 15:01:48 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char mem_c = (char)c;

	while (*s || !mem_c)
	{
		if (*s == mem_c)
			return ((char *)s);
		s++;
	}
	return (0);
}
