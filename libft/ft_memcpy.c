/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:02:19 by siokim            #+#    #+#             */
/*   Updated: 2021/12/15 10:06:47 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*tmp_dst;
	char	*tmp_src;

	tmp_src = (char *)src;
	tmp_dst = dst;
	if (tmp_dst == tmp_src)
		return (tmp_dst);
	while (n-- > 0)
		*tmp_dst++ = *tmp_src++;
	return (dst);
}
