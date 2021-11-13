/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 02:02:20 by siokim            #+#    #+#             */
/*   Updated: 2021/11/12 18:39:36 by sion             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	while (len--)
		*((char *)b + len) = (char)c;
	return (b);
}

#include <stdio.h>

int main(void)
{
   int   a[20];

   ft_memset(a, 0, sizeof(int) * 20);
   printf("%d", a[7]);
}
