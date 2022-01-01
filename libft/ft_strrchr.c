/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:19:06 by siokim            #+#    #+#             */
/*   Updated: 2022/01/01 17:58:59 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int	size;

	size = (int)ft_strlen(s);
	if (!c)
		return ((char *)(s + size));
	while (--size >= 0)
		if (s[size] == c)
			return ((char *)(s + size));
	return (0);
}
//#include <stdio.h>
//#include <string.h>
//int main()
//{
//		char *src = electric_alloc(10);

//		__builtin___strcpy_chk (src, "123456789", __builtin_object_size (src, 2 > 1 ? 1 : 0));
//		ft_strrchr(src, 'a');
//		src = electric_alloc_rev(10);
//		__builtin___strcpy_chk (src, "123456789", __builtin_object_size (src, 2 > 1 ? 1 : 0));
//		ft_strrchr(src, 'a');
//}
