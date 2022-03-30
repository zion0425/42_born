/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:17:20 by siokim            #+#    #+#             */
/*   Updated: 2022/03/11 14:51:06 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	put_str_size(char *s, char isFree)
{
	size_t	size;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}	
	size = ft_strlen(s);
	ft_putstr_fd(s, 1);
	if (isFree == 1)
		free(s);
	return (size);
}

static size_t	put_char_size(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

static size_t	identify(va_list ap, const char *str, size_t i)
{
	size_t	res_size;

	res_size = 0;
	if (str[i + 1] == 'd' || str[i + 1] == 'i')
		res_size = put_str_size(ft_itoa(va_arg(ap, int)), 1);
	else if (str[i + 1] == 'c')
		res_size = put_char_size(va_arg(ap, int));
	else if (str[i + 1] == 's')
		res_size = put_str_size(va_arg(ap, char *), 0);
	else if (str[i + 1] == 'u')
		res_size = put_str_size(unsigned_ft_itoa(va_arg(ap, unsigned int)), 1);
	else if (str[i + 1] == '%')
		res_size = put_char_size('%');
	else if (str[i + 1] == 'x' || str[i + 1] == 'X')
		res_size = hex_print(va_arg(ap, unsigned int), (str[i + 1] == 'X'));
	else if (str[i + 1] == 'p')
		res_size = hex_print(va_arg(ap, unsigned long), 2);
	return (res_size);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	res_size;
	size_t	i;

	if (!str || !str[0])
		return (0);
	va_start(ap, str);
	res_size = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			res_size += identify(ap, str, i++);
		else
		{
			write(1, &str[i], 1);
			res_size += 1;
		}
		i++;
	}
	return (res_size);
}
