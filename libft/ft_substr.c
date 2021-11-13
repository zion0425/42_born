/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 05:07:28 by siokim            #+#    #+#             */
/*   Updated: 2021/11/09 21:41:52 by sion             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	j;
	unsigned int	i;
	char			*tmp_str;

	j = start;
	i = -1;
	tmp_str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!tmp_str)
		return (NULL);
	while (++i < len && s[j])
		tmp_str[i] = s[j++];
	tmp_str[i] = 0;
	return (tmp_str);
}
