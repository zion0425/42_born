/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:17:20 by siokim            #+#    #+#             */
/*   Updated: 2022/02/10 20:24:21 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	identify(char c, ...)
{
	if (c == 'c')
	if (c == 's')
	if (c == 'p')
	if (c == 'd')
	if (c == 'i')
	if (c == 'u')
	if (c == 'x')
	if (c == 'X')
	if (c == '%')
}

/*
%c는 단일 문자 (character) 한 개를 출력합니다.
%s는 문자열 (string) 을 출력합니다.
%p는 void * 형식의 포인터 인자를 16진수로 출력합니다.
%d는 10진수 숫자를 출력합니다.
%i는 10진수 정수를 출력합니다.
%u는 부호 없는 10진수 숫자를 출력합니다.
%x는 소문자를 사용하여 숫자를 16진수로 출력합니다.
%X는 대문자를 사용하여 숫자를 16진수로 출력합니다.
%%는 퍼센트 기호 (%) 를 출력합니다.
*/
int	ft_printf(const char *str, ...)
{
	va_list	op;

	va_start(op, args);

	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			int identify(str[i])
	}

}
