/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:17:20 by siokim            #+#    #+#             */
/*   Updated: 2022/02/12 18:12:42 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	hex_size(unsigned int str)
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

char	*hex_print(unsigned int str, char isUpper)
{
	char 	*tmp_str;
	size_t	i = 0;
	tmp_str = 0;
	tmp_str = malloc(sizeof(char) * hex_size(str));
	while (str > 0)
	{
		if (isUpper)
			tmp_str[i] = "0123456789ABCDEF"[str % 16];
		else
			tmp_str[i] = "0123456789abcdef"[str % 16];

		i++;
		str /= 16;
	}
	while (tmp_str[--i])
		write(1, &tmp_str[i], 1);
	free(tmp_str);
	return (tmp_str);
}

void	identify(va_list ap, const char *str, size_t i)
{
	if (str[i + 1] == 'd')
		ft_putstr_fd(ft_itoa(va_arg(ap, int)), 1);
	if (str[i + 1] == 'i')
		ft_putstr_fd(ft_itoa(va_arg(ap, int)), 1);
	if (str[i + 1] == 'c')
		ft_putstr_fd(ft_itoa(va_arg(ap, int)), 1);
	if (str[i + 1] == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	if (str[i + 1] == 'u')
		ft_putstr_fd(ft_itoa(va_arg(ap, unsigned int)), 1);
	if (str[i + 1] == '%')
		ft_putstr_fd("%", 1);
	if (str[i + 1] == 'x')
		hex_print(va_arg(ap, int), 0);
	if (str[i + 1] == 'X')
		hex_print(va_arg(ap, int), 1);
	//if (str[i + 1] == 'p')
	//else
		//error
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;

	va_start(ap, str);

	size_t	i;
	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			identify(ap, str, i++);
		else
			write(1, &str[i], 1);
		i++;

	}
	return (0);
}

#include <stdio.h>

int main()
{
	int a = 'A';
	//%d는 10진수 숫자를 출력합니다.
	printf("d : %d\n", a);
	ft_printf("%d\n", a);

	//%i는 10진수 정수를 출력합니다.
	printf("i : %i\n", a);
	ft_printf("%i\n", a);

	//%c는 단일 문자 (character) 한 개를 출력합니다.
	// char int 형 변환 필요..
	printf("c : %c\n", a);
	ft_printf("%c\n", a);

	//%s는 문자열 (string) 을 출력합니다.
	//seg fault
	printf("s : %s\n", a);
	ft_printf("%s\n", a);

	//%u는 부호 없는 10진수 숫자를 출력합니다.
	printf("u : %u\n", a);
	ft_printf("%u\n", a);

	//%%는 퍼센트 기호 (%) 를 출력합니다.
	printf("%% : %%\n");
	ft_printf("%%\n");

	//%x는 소문자를 사용하여 숫자를 16진수로 출력합니다.
	printf("%x\n", &a);
	ft_printf("%x\n", &a);

	//%X는 대문자를 사용하여 숫자를 16진수로 출력합니다.
	printf("%X\n", &a);
	ft_printf("%X\n", &a);

	//%p는 void * 형식의 포인터 인자를 16진수로 출력합니다.
	printf("p : %p\n", &a);
}
