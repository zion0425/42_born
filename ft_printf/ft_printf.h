/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:17:25 by siokim            #+#    #+#             */
/*   Updated: 2022/02/16 15:39:13 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

static size_t	hex_size(unsigned long long str);
static size_t	put_hex(unsigned long long str, char isUpper);
static size_t	numsize(unsigned int n);
static size_t	identify(va_list ap, const char *str, size_t i);
static size_t	put_char_size(char c);
static size_t	put_str_size(char *s, char isFree);
char			*unsigned_ft_itoa(unsigned long long n);
int				ft_printf(const char *str, ...);
size_t			hex_print(unsigned long long str, char isUpper);

#endif