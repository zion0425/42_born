/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:02:19 by siokim            #+#    #+#             */
/*   Updated: 2022/01/10 14:58:55 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_dst;
	const unsigned char	*tmp_src = (unsigned char *)src;

	tmp_dst = (unsigned char *)dst;
	if (tmp_dst == tmp_src)
		return (tmp_dst);
	while (n-- > 0)
		*tmp_dst++ = *tmp_src++;
	return (dst);
}
