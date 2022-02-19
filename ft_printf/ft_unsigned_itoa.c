/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:37:08 by siokim            #+#    #+#             */
/*   Updated: 2022/02/19 13:41:13 by sion             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	numsize(unsigned int n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*unsigned_ft_itoa(unsigned int n)
{
	size_t			size;
	char			*str;

	size = numsize(n);
	if (n < 0)
		size++;
	str = malloc(size + 1);
	if (!str)
		return (0);
	if (n == 0)
		str[0] = '0';
	str[size] = 0;
	while (n > 0)
	{
		str[--size] = n % 10 + 48;
		n /= 10;
	}
	return (str);
}
