/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:55:52 by siokim            #+#    #+#             */
/*   Updated: 2021/12/16 18:32:47 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	i = ft_strlen(s1);
	str = (char *)malloc(sizeof(s1) * (i + 1));
	if (!str)
		return (0);
	str[i] = 0;
	while (i--)
		str[i] = s1[i];
	return (str);
}
