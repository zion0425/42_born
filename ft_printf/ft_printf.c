/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:17:20 by siokim            #+#    #+#             */
/*   Updated: 2022/02/13 19:09:25 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	put_str_size(char *s)
{
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

size_t	put_char_size(char c)
{
	ft_putchar_fd(c,  1);
	return (1);
}

size_t	identify(va_list ap, const char *str, size_t i)
{
	size_t	res_size;

	res_size = 99;
	if (str[i + 1] == 'd')
		res_size = put_str_size(ft_itoa(va_arg(ap, int)));
	if (str[i + 1] == 'i')
		res_size = put_str_size(ft_itoa(va_arg(ap, int)));
	if (str[i + 1] == 'c')
		res_size = put_char_size(va_arg(ap, int));
	if (str[i + 1] == 's')
		res_size = put_str_size(va_arg(ap, char *));
	if (str[i + 1] == 'u')
		res_size = put_str_size(unsigned_ft_itoa(va_arg(ap, unsigned int)));
	if (str[i + 1] == '%')
		res_size = put_char_size('%');
	if (str[i + 1] == 'x')
		res_size = hex_print(va_arg(ap, unsigned int), 0);
	if (str[i + 1] == 'X')
		res_size = hex_print(va_arg(ap, unsigned int), 1);
	if (str[i + 1] == 'p')
		res_size = hex_print(va_arg(ap, unsigned long long), 2);
	return (res_size);
	//else
		//error
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	res_size;

	res_size = 0;
	va_start(ap, str);
	size_t	i;
	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			res_size += identify(ap, str, i++) - 1;
		else
			write(1, &str[i], 1);
		i++;
	}
	return (res_size + i - 1);
}

#include <stdio.h>

int main()
{
	//char *a = "AB";
	int	a = -122;
	//char	a = 'A';

	//%d는 10진수 숫자를 출력합니다.
	//printf("\nhi : %d", printf("%d\n",a));
	//printf("\nhi : %d", ft_printf("%d\n", a));

	////%i는 10진수 정수를 출력합니다.
	//printf("\nhi : %d", printf("%i\n",a));
	//printf("\nhi : %d", ft_printf("%i\n", a));

	////%c는 단일 문자 (character) 한 개를 출력합니다.
	//printf("\nhi : %d", printf("%c\n",a));
	//printf("\nhi : %d", ft_printf("%c\n", a));

	////%s는 문자열 (string) 을 출력합니다.
	//printf("\nhi : %d", printf("a%s\n",a));
	//printf("\nhi : %d", ft_printf("a%s\n", a));

	////%u는 부호 없는 10진수 숫자를 출력합니다.
	//printf("\nhi : %d", printf("a%u\n",a));
	//printf("\nhi : %d", ft_printf("a%u\n", a));

	////%%는 퍼센트 기호 (%) 를 출력합니다.
	//printf("\nhi : %d", printf("a%%\n"));
	//printf("\nhi : %d", ft_printf("a%%\n"));

	////%x는 소문자를 사용하여 숫자를 16진수로 출력합니다.
	//printf("\nhi : %d", printf("a%x\n",a));
	//printf("\nhi : %d", ft_printf("a%x\n", a));

	////%X는 대문자를 사용하여 숫자를 16진수로 출력합니다.
	//printf("\nhi : %d", printf("a%X\n",a));
	//printf("\nhi : %d", ft_printf("a%X\n", a));

	//%p는 void * 형식의 포인터 인자를 16진수로 출력합니다.
	printf("\nhi : %d", printf("a%p\n",&a));
	printf("\nhi : %d", ft_printf("a%p\n", &a));
}
