/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:55:52 by siokim            #+#    #+#             */
/*   Updated: 2022/01/01 17:08:54 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdlib.h>

//size_t	ft_strlen(const char *s)
//{
//	int	i;

//	i = 0;
//	while (s[i])
//		i++;
//	return (i);
//}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	i = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	str[i] = 0;
	while (i--)
		str[i] = s1[i];
	return (str);
}
//#include <stdio.h>
//int main()
//{
//	char *str;
//	char *tmp = "this is a normal test";

//	str = ft_strdup(tmp);
//	printf("%s\n", str);

//}
