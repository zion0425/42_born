/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:35:48 by siokim            #+#    #+#             */
/*   Updated: 2022/02/13 19:08:54 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	hex_size(unsigned int str)
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

size_t	hex_print(unsigned int str, char isUpper)
{
	char 	*tmp_str;
	size_t	i;
	const size_t size = hex_size(str);

	i = 0;
	tmp_str = malloc(sizeof(char) * (size));
	if (!tmp_str)
		return (0);
	while (str > 0)
	{
		if (isUpper == 1)
			tmp_str[i] = "0123456789ABCDEF"[str % 16];
		else
			tmp_str[i] = "0123456789abcdef"[str % 16];
		i++;
		str /= 16;
	}
	if (isUpper == 2)
		write(1, "0x", 2);
	while (tmp_str[--i])
		write(1, &tmp_str[i], 1);
	free(tmp_str);
	if (isUpper == 2)
		return (size + 2);
	return (size);
}
