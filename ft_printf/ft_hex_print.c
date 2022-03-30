/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:35:48 by siokim            #+#    #+#             */
/*   Updated: 2022/03/11 14:15:21 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	hex_size(unsigned long str)
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

static void	put_hex(unsigned long str, char isUpper)
{
	size_t	size;

	size = 0;
	if (str > 0)
	{
		if (isUpper == 1)
		{
			put_hex(str / 16, isUpper);
			write(1, &"0123456789ABCDEF"[str % 16], 1);
		}
		else
		{
			put_hex(str / 16, isUpper);
			write(1, &"0123456789abcdef"[str % 16], 1);
		}
	}
}

size_t	hex_print(unsigned long str, char isUpper)
{
	int		i;
	size_t	size;

	size = hex_size(str);
	i = 0;
	if (isUpper == 2)
	{
		write(1, "0x", 2);
		size += 2;
	}
	if (str == 0)
	{
		write(1, "0", 1);
		size ++;
		return (size);
	}
	put_hex(str, isUpper);
	return (size);
}
