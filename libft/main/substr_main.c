/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sion <siokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:40:15 by sion              #+#    #+#             */
/*   Updated: 2021/11/09 21:40:59 by sion             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_substr(char *s, unsigned int a, size_t b);

int	main(void)
{
	printf("%s\n", ft_substr("abc", 1, 2));
	printf("%s", ft_substr("abc", 1, 0));
}
