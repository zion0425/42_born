/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:17:25 by siokim            #+#    #+#             */
/*   Updated: 2022/02/15 12:08:21 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int n);
int	ft_toupper(int c);
int	ft_printf(const char *args, ...);
char	*unsigned_ft_itoa(unsigned long long n);
size_t	hex_print(unsigned long long str, char isUpper);

#endif
