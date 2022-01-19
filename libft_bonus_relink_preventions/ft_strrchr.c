/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:19:06 by siokim            #+#    #+#             */
/*   Updated: 2022/01/07 12:01:36 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	size;

	size = (int)ft_strlen(s);
	if (!c)
		return ((char *)(s + size));
	while (--size >= 0)
		if (s[size] == (char)c)
			return ((char *)(s + size));
	return (0);
}
