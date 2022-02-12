/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 05:07:28 by siokim            #+#    #+#             */
/*   Updated: 2022/01/07 15:49:25 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	j;
	unsigned int	i;
	char			*tmp_str;

	j = start;
	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	tmp_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp_str)
		return (0);
	while (i < len && s[j] && start < ft_strlen(s))
		tmp_str[i++] = s[j++];
	tmp_str[i] = 0;
	return (tmp_str);
}
