/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:19:06 by siokim            #+#    #+#             */
/*   Updated: 2022/02/16 14:59:31 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			size;
	const char	mem_c = (char)c;

	size = (int)ft_strlen(s);
	if (!mem_c)
		return ((char *)(s + size));
	while (--size >= 0)
		if (s[size] == mem_c)
			return ((char *)(s + size));
	return (0);
}
