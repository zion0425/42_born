/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 02:02:20 by siokim            #+#    #+#             */
/*   Updated: 2022/05/30 16:04:31 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	const unsigned char	mem_c = (unsigned char)c;
	unsigned char		*mem_b;

	mem_b = (unsigned char *)b;
	while (len--)
		*(mem_b + len) = mem_c;
	return (mem_b);
}
