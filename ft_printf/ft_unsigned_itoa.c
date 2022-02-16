/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:37:08 by siokim            #+#    #+#             */
/*   Updated: 2022/02/16 15:37:46 by siokim           ###   ########.fr       */
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

char	*unsigned_ft_itoa(unsigned long long n)
{
	size_t			size;
	char			*str;
	unsigned int	num;

	size = numsize(n);
	if (n < 0)
		size++;
	str = malloc(size + 1);
	if (!str)
		return (0);
	num = n;
	if (num == 0)
		str[0] = '0';
	str[size] = 0;
	while (num > 0)
	{
		str[--size] = num % 10 + 48;
		num /= 10;
	}
	return (str);
}
