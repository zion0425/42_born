/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:25:53 by siokim            #+#    #+#             */
/*   Updated: 2021/11/16 22:15:26 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*stpncpy(char *dst, const char *src, size_t len)
{
	size_t *dst_len;
	size_t *src_len;
	size_t n;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);

	n = 0;
	while ((*dst || src[n]) && n < len)
	{
		*dst = src[n];
		*dst++;
	}
	if (n < len)
		while (*dst)
			*dst++ = 0;
	*dst = 0;
	return (dst);
}
