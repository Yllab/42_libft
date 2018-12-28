/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitooa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:10:36 by hbally            #+#    #+#             */
/*   Updated: 2018/11/16 10:30:23 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

#include <stdio.h>

char				*ft_uitooa(unsigned int n)
{
	const char		*octal = "01234567";
	unsigned int	digit;
	size_t			len;
	char			*ret;

	len = 0;
	if (n == 0)
		return (ft_itoa(0));
	if (!(ret = ft_strnew(len)))
		return (NULL);
	digit = 01u;
	//debug
	int i = 0;
	while (digit < n || i++ < 10)
	{
		printf("%o\n", digit);
		digit &= digit << 1;
	}
	digit -= digit >> 1;
	while (n != 0)
	{
		if (!(ret = ft_str_realloc(ret, ++len)))
			return (NULL);
		ret[len - 1] = octal[n / digit];
		n -= digit * (n / digit);
		digit /= 010;
	}
	return (ret);
}
