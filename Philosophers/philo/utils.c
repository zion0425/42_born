/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siokim <siokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:51:30 by siokim            #+#    #+#             */
/*   Updated: 2022/08/10 17:13:05 by siokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_atoi(const char *str)
{
    int sign;
    int result;

    sign = 1;
    result = 0;
    while ((*str >= 9 && *str <= 13) || *str == 32)
        str++;
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign *= -1;
        str ++;
    }
    while (*str >= 48 && *str <= 57)
    {
        result = result * 10 + *str - 48;
        str++;
    }
    return (result * sign);
}

size_t  ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int    *ft_cpy(int *src, int argc)
{
    int    *dst;
    int  i;
    int  src_len;

    i = -1;
    src_len = argc;
    dst = malloc(sizeof(long) * src_len - 1);
    while (++i < src_len)
        dst[i] = src[i];
    return (dst);
}
