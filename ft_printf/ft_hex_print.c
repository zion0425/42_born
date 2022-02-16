/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:35:48 by siokim            #+#    #+#             */
/*   Updated: 2022/02/16 12:15:24 by siokim           ###   ########.fr       */
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

size_t	hex_print(unsigned long long str, char isUpper)
{
	char 	*tmp_str;
	int	i;
	size_t	size;

	size = hex_size(str);
	i = 0;
	if (isUpper != 2)
		str = (unsigned int)str;
	else
		write(1, "0x", 2);
	if (str == 0)
	{
		write(1, "0" , 1);
		if (isUpper == 2)
			return (3);
		return (1);
	}
	tmp_str = malloc(sizeof(char) * (size));
	if (!tmp_str)
		return (0);
	while (str > 0)
	{
		if (isUpper == 1)
			tmp_str[i++] = "0123456789ABCDEF"[str % 16];
		else
			tmp_str[i++] = "0123456789abcdef"[str % 16];
		str /= 16;
	}
	while (--i >= 0)
		write(1, &tmp_str[i], 1);
	free(tmp_str);
	if (isUpper == 2)
		size += 2;
	return (size);
}
