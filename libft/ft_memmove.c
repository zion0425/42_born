/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:07:55 by siokim            #+#    #+#             */
/*   Updated: 2021/12/16 17:55:26 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	if (!tmp_src || !tmp_src)
		return (dst);
	if (tmp_dst > tmp_src)
		while (len--)
			tmp_dst[len] = tmp_src[len];
	else
		while (len--)
			*tmp_dst++ = *tmp_src++;
	return (dst);
}
