/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:35:48 by siokim            #+#    #+#             */
/*   Updated: 2022/02/16 15:37:33 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	hex_size(unsigned long long str)
{
	size_t	size;

	size = 0;
	while (str > 0)
	{
		str /= 16;
		size ++;
	}
	return (size);
}

static size_t	put_hex(unsigned long long str, char isUpper)
{
	size_t	size;

	size = 0;
	if (isUpper != 2)
		str = (unsigned int)str;
	if (str > 0)
	{
		if (isUpper == 1)
		{
			size += put_hex(str / 16, isUpper);
			write(1, &"0123456789ABCDEF"[str % 16], 1);
		}
		else
		{
			size += put_hex(str / 16, isUpper);
			write(1, &"0123456789abcdef"[str % 16], 1);
		}
		size++;
	}
	return (size);
}

size_t	hex_print(unsigned long long str, char isUpper)
{
	int		i;
	size_t	size;

	size = hex_size(str);
	i = 0;
	if (isUpper == 2)
		write(1, "0x", 2);
	if (str == 0)
	{
		write(1, "0", 1);
		if (isUpper == 2)
			return (3);
		return (1);
	}
	size = put_hex(str, isUpper);
	if (isUpper == 2)
		size += 2;
	return (size);
}
