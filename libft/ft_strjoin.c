/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 05:28:10 by siokim            #+#    #+#             */
/*   Updated: 2021/12/29 15:21:25 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	tmp_str = (char *)malloc(sizeof(char *) * \
		(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!tmp_str)
		return (0);
	while (s1[i])
	{
		tmp_str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		tmp_str[i] = s2[j++];
		i++;
	}
	tmp_str[i] = 0;
	return (tmp_str);
}
