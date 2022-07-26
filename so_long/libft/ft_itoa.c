/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:22:48 by siokim            #+#    #+#             */
/*   Updated: 2022/07/25 10:36:11 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	numsize(int n)
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

char	*ft_itoa(int n)
{
	size_t	size;
	char	*str;
	long	num;

	size = numsize(n);
	if (n < 0)
		size++;
	str = malloc(size + 1);
	if (!str)
		return (0);
	num = n;
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	str[size] = 0;
	while (num > 0)
	{
		str[--size] = num % 10 + 48;
		num /= 10;
	}
	return (str);
}
