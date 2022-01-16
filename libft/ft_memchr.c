/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:05:52 by siokim            #+#    #+#             */
/*   Updated: 2022/01/10 14:55:27 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str = (unsigned char *)s;
	const unsigned char	mem_c = (unsigned char)c;
	size_t				i;

	i = 0;
	while (i++ < n)
	{
		if (*str == mem_c)
			return ((unsigned char *)str);
		str++;
	}
	return (0);
}
