/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoxa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:10:36 by hbally            #+#    #+#             */
/*   Updated: 2018/11/16 10:30:23 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char				*ft_uitoxa(unsigned int n)
{
	const char		*hexa = "0123456789ABCDEF";
	unsigned int	digit;
	size_t			len;
	char			*ret;

	len = 0;
	if (n == 0)
		return (ft_itoa(0));
	if (!(ret = ft_strnew(len)))
		return (NULL);
	digit = 0x10u << ((sizeof(int) - 1) * 8);
	while (n / digit == 0)
		digit = digit >> 4;
	while (digit != 0)
	{
		if (!(ret = ft_str_realloc(ret, ++len)))
			return (NULL);
		ret[len - 1] = hexa[n / digit];
		n -= digit * (n / digit);
		digit = digit >> 4;
	}
	return (ret);
}
