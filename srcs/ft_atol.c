/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 20:00:42 by hbally            #+#    #+#             */
/*   Updated: 2018/12/20 17:46:26 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//debug
#include <stdio.h>

long			ft_atol(const char *str)
{
	int 		i;
	long 		sign;
	long 		ret;

	i = 0;
	sign = 1;
	ret = 0;
	while ((str[i] >= 7 && str[i] <= 13) || str[i] == ' ')
		i++;
	sign = str[i] == '-' ? -1 : 1;
	i += (str[i] == '+' || str[i] == '-') ? 1 : 0;
	while (ft_isdigit(str[i]))
	{
		printf("ret = %ld", ret);
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	printf("ret = %ld", ret);
	return (ret * sign);
}
